#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x1fffffffffffffff;
const double INFD = 1e20;
const double EPS = 1e-9;
const double PI = atan(1) * 4;
const long long M = 1000000007;
long long scan() {
  long long r;
  scanf("%lld", &r);
  return r;
}
void scanstr(char *buf) { scanf("%s", buf); }
void dumpVI(vector<long long> &x) {
  for (auto v : x) {
    cerr << v << ",";
  }
  cerr << endl;
}
void tarjan_dfs(long long current, long long parent, long long &timer,
                long long &cn, vector<long long> &vtime,
                vector<long long> &rtime, vector<long long> &v2e0,
                vector<long long> &e2t, vector<long long> &e2n,
                vector<long long> &v2c, stack<long long> &stk) {
  stk.push(current);
  rtime[current] = vtime[current] = timer++;
  for (long long e = v2e0[current]; e >= 0; e = e2n[e]) {
    long long next = e2t[e];
    if (next == parent) continue;
    if (vtime[next] == -1) {
      tarjan_dfs(next, current, timer, cn, vtime, rtime, v2e0, e2t, e2n, v2c,
                 stk);
      rtime[current] = min(rtime[current], rtime[next]);
    } else if (v2c[next] == -1)
      rtime[current] = min(rtime[current], vtime[next]);
  }
  if (vtime[current] == rtime[current]) {
    while (true) {
      long long v = stk.top();
      v2c[v] = cn;
      stk.pop();
      if (v == current) break;
    }
    cn++;
  }
}
void work(const vector<long long> &v2e0, const vector<long long> &e2t,
          const vector<long long> &e2c, const vector<long long> &e2n,
          vector<long long> &score, vector<long long> &isSp, long long spn,
          long long current, long long parent, vector<long long> &spCount,
          vector<long long> &fio, vector<long long> &fore) {
  fio[current] = score[current];
  spCount[current] = (isSp[current]) ? 1 : 0;
  for (long long e = v2e0[current]; e >= 0; e = e2n[e]) {
    long long next = e2t[e];
    if (next == parent) continue;
    work(v2e0, e2t, e2c, e2n, score, isSp, spn, next, current, spCount, fio,
         fore);
    spCount[current] += spCount[next];
    fore[next] = (spCount[next] > 0 && spCount[next] < spn)
                     ? max(0LL, fio[next] - e2c[e])
                     : fio[next];
    fio[current] += fore[next];
  }
}
void calc(vector<long long> &v2e0, vector<long long> &e2t,
          vector<long long> &e2c, vector<long long> &e2n, long long spn,
          long long current, long long parent, vector<long long> &spCount,
          vector<long long> &fio, vector<long long> &fore,
          vector<long long> &ans, long long fioParent, long long srcEdge) {
  long long parentScore = (spCount[current] > 0 && spCount[current] < spn)
                              ? max(0LL, fioParent - e2c[srcEdge])
                              : fioParent;
  ans[current] = fio[current] + parentScore;
  for (long long e = v2e0[current]; e >= 0; e = e2n[e]) {
    long long next = e2t[e];
    if (next == parent) continue;
    long long fioAsChild = fio[current] - fore[next] + parentScore;
    calc(v2e0, e2t, e2c, e2n, spn, next, current, spCount, fio, fore, ans,
         fioAsChild, e);
  }
}
int main() {
  long long n = scan();
  long long m = scan();
  long long k = scan();
  vector<long long> c(n);
  vector<long long> w(m);
  vector<long long> isSp0(n);
  for (long long i = 0; i < k; ++i) isSp0[scan() - 1] = 1;
  for (long long i = 0; i < n; ++i) c[i] = scan();
  for (long long i = 0; i < m; ++i) w[i] = scan();
  vector<long long> _v2e0(n, -1);
  vector<long long> _e2f;
  vector<long long> _e2t;
  vector<long long> _e2c;
  vector<long long> _e2n;
  for (long long i = 0; i < m; ++i) {
    long long x = scan() - 1;
    long long y = scan() - 1;
    _e2f.push_back(x);
    _e2t.push_back(y);
    _e2c.push_back(w[i]);
    _e2n.push_back(_v2e0[x]);
    _v2e0[x] = _e2f.size() - 1;
    _e2f.push_back(y);
    _e2t.push_back(x);
    _e2c.push_back(w[i]);
    _e2n.push_back(_v2e0[y]);
    _v2e0[y] = _e2f.size() - 1;
  }
  long long timer = 0;
  long long cn = 0;
  vector<long long> vtime(n, -1);
  vector<long long> rtime(n, -1);
  vector<long long> _v2c(n, -1);
  stack<long long> stk;
  tarjan_dfs(0, -1, timer, cn, vtime, rtime, _v2e0, _e2t, _e2n, _v2c, stk);
  vector<long long> v2e0(cn, -1);
  vector<long long> e2n;
  vector<long long> e2c;
  vector<long long> e2t;
  vector<long long> e2f;
  set<tuple<long long, long long>> eset;
  for (long long i = 0; i < m; ++i) {
    long long cx = _v2c[_e2f[i * 2]], cy = _v2c[_e2t[i * 2]];
    if (cx == cy) continue;
    if (cx > cy) swap(cx, cy);
    if (eset.find(make_tuple(cx, cy)) != eset.end()) continue;
    e2n.push_back(v2e0[cx]);
    e2c.push_back(_e2c[i * 2]);
    e2f.push_back(cx);
    e2t.push_back(cy);
    v2e0[cx] = e2n.size() - 1;
    e2n.push_back(v2e0[cy]);
    e2c.push_back(_e2c[i * 2]);
    e2t.push_back(cx);
    e2f.push_back(cy);
    v2e0[cy] = e2n.size() - 1;
  }
  vector<long long> score(cn);
  vector<long long> isSp(cn);
  for (long long i = 0; i < n; ++i) {
    score[_v2c[i]] += c[i];
    isSp[_v2c[i]] |= isSp0[i];
  }
  long long spn = 0;
  for (long long i = 0; i < cn; ++i)
    if (isSp[i]) spn++;
  vector<long long> spCount(cn);
  vector<long long> fio(cn);
  vector<long long> fore(cn);
  work(v2e0, e2t, e2c, e2n, score, isSp, spn, 0, -1, spCount, fio, fore);
  vector<long long> ans(cn);
  calc(v2e0, e2t, e2c, e2n, spn, 0, -1, spCount, fio, fore, ans, 0, -1);
  for (long long i = 0; i < n - 1; ++i) {
    cout << ans[_v2c[i]] << " ";
  }
  cout << ans[_v2c[n - 1]] << endl;
  return 0;
}

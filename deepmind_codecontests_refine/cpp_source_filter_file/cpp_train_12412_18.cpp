#include <bits/stdc++.h>
using namespace std;
const int N = 300043;
const int K = 5;
int x, y, z, n;
long long a[N];
map<vector<vector<int> >, int> d;
int cnt;
int p;
vector<vector<int> > state_log;
int mex(const vector<int>& a) {
  for (int i = 0; i < a.size(); i++) {
    bool f = false;
    for (auto x : a)
      if (x == i) f = true;
    if (!f) return i;
  }
  return a.size();
}
vector<vector<int> > go(vector<vector<int> > s) {
  int f1 = mex({s[0][K - x], s[1][K - y], s[2][K - z]});
  int f2 = mex({s[0][K - x], s[2][K - z]});
  int f3 = mex({s[0][K - x], s[1][K - y]});
  vector<vector<int> > nw = s;
  nw[0].push_back(f1);
  nw[1].push_back(f2);
  nw[2].push_back(f3);
  for (int i = 0; i < 3; i++) nw[i].erase(nw[i].begin());
  return nw;
}
void precalc() {
  d.clear();
  vector<vector<int> > cur(3, vector<int>(K, 0));
  cnt = 0;
  state_log.clear();
  while (!d.count(cur)) {
    d[cur] = cnt;
    state_log.push_back({cur[0].back(), cur[1].back(), cur[2].back()});
    cur = go(cur);
    cnt++;
  }
  p = cnt - d[cur];
}
int get_grundy(long long x, int t) {
  if (x < cnt)
    return state_log[x][t];
  else {
    int pp = cnt - p;
    x -= pp;
    return state_log[pp + (x % p)][t];
  }
}
void read() {
  scanf("%d %d %d %d", &n, &x, &y, &z);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
}
int check(int x, int y) { return x == y ? 1 : 0; }
long long chk = 0, chk2 = 0;
void solve() {
  precalc();
  int ans = 0;
  for (int i = 0; i < n; i++) ans ^= get_grundy(a[i], 0);
  int res = 0;
  if (chk2) {
    cout << "xor: " << ans << " || " << cnt << " " << p << endl;
    for (long long i = 1; i <= 20; i++) {
      cout << i << " ---> ";
      for (long long j = 0; j < 3; j++) cout << get_grundy(i, j) << " ";
      cout << endl;
    }
  }
  for (int i = 0; i < n; i++) {
    ans ^= get_grundy(a[i], 0);
    res += check(ans, get_grundy(max(0ll, a[i] - x), 0));
    res += check(ans, get_grundy(max(0ll, a[i] - y), 1));
    res += check(ans, get_grundy(max(0ll, a[i] - z), 2));
    ans ^= get_grundy(a[i], 0);
  }
  printf("%d\n", res);
}
int main() {
  int t;
  scanf("%d", &t);
  if (t == 10) chk = 1;
  for (int i = 0; i < t; i++) {
    read();
    if (i == 0 && n == 6) chk = 0;
    if (chk) {
      if (i == 1) chk2 = 1;
    }
    solve();
  }
}

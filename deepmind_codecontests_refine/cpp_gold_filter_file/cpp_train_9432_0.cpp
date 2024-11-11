#include <bits/stdc++.h>
using namespace std;
const long long N = 400010, INF = 1ll << 60;
struct edge {
  long long la, b, v;
} con[N << 1];
long long tot, fir[N];
void add(long long from, long long to, long long val) {
  con[++tot] = (edge){fir[from], to, val};
  fir[from] = tot;
}
long long cnt, cir[N], rt, vis[N], n, dist[N], inc[N], dep[N], ans, val[2][N],
    mn = INF;
set<pair<long long, long long> > st[2];
set<pair<long long, long long> >::iterator t1, t2;
long long getcir(long long pos, long long fa) {
  if (vis[pos]) {
    rt = pos;
    return 1;
  }
  long long tmp;
  vis[pos] = 1;
  for (long long i = fir[pos]; i; i = con[i].la) {
    if (con[i].b == fa) continue;
    if (tmp = getcir(con[i].b, pos), tmp) {
      if (tmp == 1) {
        cir[++cnt] = pos;
        dist[cnt] = con[i].v;
        inc[pos] = 1;
        if (pos != rt) return 1;
      }
      return 2;
    }
  }
  return 0;
}
long long dfs(long long pos, long long fa) {
  long long cur = 0, tmp;
  for (long long i = fir[pos]; i; i = con[i].la) {
    if (inc[con[i].b] || con[i].b == fa) continue;
    tmp = dfs(con[i].b, pos) + con[i].v;
    ans = max(ans, cur + tmp);
    cur = max(cur, tmp);
  }
  return cur;
}
long long solve(long long k) {
  t1 = st[k].end();
  t1--;
  long long ret = t1->first, p = t1->second;
  assert(st[k ^ 1].erase(make_pair(val[k ^ 1][p], p)));
  t2 = st[k ^ 1].end();
  t2--;
  assert(t2->second != p);
  ret += t2->first;
  st[k ^ 1].insert(make_pair(val[k ^ 1][p], p));
  return ret;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long x, y, z;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> x >> y >> z;
    add(x, y, z);
    add(y, x, z);
  }
  getcir(1, 0);
  for (long long i = 1; i <= cnt; ++i) dep[i] = dfs(cir[i], 0);
  for (long long i = 1; i <= cnt * 2; ++i) {
    long long j = (i - 1) % cnt + 1;
    val[1][i] = val[1][i - 1] + dist[j];
    val[0][i] = val[0][i - 1] - dist[j];
  }
  for (long long i = 1; i <= cnt * 2; ++i) {
    long long j = (i - 1) % cnt + 1;
    val[0][i] += dep[j];
    val[1][i] += dep[j];
  }
  for (long long k = 0; k < 2; ++k)
    for (long long i = 1; i < cnt; ++i) st[k].insert(make_pair(val[k][i], i));
  for (long long i = cnt; i < 2 * cnt; ++i) {
    for (long long k = 0; k < 2; ++k) st[k].insert(make_pair(val[k][i], i));
    long long tmp = 0;
    for (long long k = 0; k < 2; ++k) tmp = max(tmp, solve(k));
    if (tmp < mn) mn = tmp;
    for (long long k = 0; k < 2; ++k)
      assert(st[k].erase(make_pair(val[k][i - cnt + 1], i - cnt + 1)));
  }
  ans = max(ans, mn);
  cout << ans << endl;
  return 0;
}

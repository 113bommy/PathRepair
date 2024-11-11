#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const long long SZ = 1010, SSZ = 100010, APB = 26, one = 93,
                INF = 0x3f3f3f3f3f3f3f3f, mod = 1000000007;
long long n, m, bg, fn, cnt;
long long to[SSZ], wt[SSZ], head[SZ];
long long nex[SSZ], mk[SSZ];
long long dfn[SZ], low[SZ], tot;
bool vst[SZ];
void add(long long u, long long v, long long w) {
  ++cnt;
  nex[cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v, wt[cnt] = w;
}
bool dfs(long long x) {
  vst[x] = 1;
  if (x == fn) return 1;
  for (long long i = head[x]; i != -1; i = nex[i]) {
    long long t = to[i];
    if (!vst[t]) {
      mk[i] = 1;
      if (dfs(t)) return 1;
      mk[i] = 0;
    }
  }
  return 0;
}
stack<long long> stk;
void tar(long long x, long long p, long long &res2, long long &eg2) {
  dfn[x] = low[x] = ++tot;
  vst[x] = 1;
  for (long long i = head[x]; i != -1; i = nex[i]) {
    if (i != (p ^ 1) && mk[i] != 2 && mk[i ^ 1] != 2) {
      long long t = to[i], w = wt[i];
      if (!dfn[t]) {
        tar(t, i, res2, eg2);
        low[x] = min(low[x], low[t]);
      } else
        low[x] = min(low[x], low[t]);
      if (low[x] < low[t] && dfn[fn] >= dfn[t]) {
        if (w < res2) {
          res2 = w, eg2 = i;
        }
      }
    }
  }
}
void init() {
  cin >> n >> m >> bg >> fn;
  cnt = -1;
  memset(head, -1, sizeof(head));
  for (long long i = 1; i <= m; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    add(b, a, c);
  }
  dfs(bg);
  if (vst[fn] == 0) {
    cout << 0 << endl;
    return;
  }
  long long res = INF, vt1 = -1, vt2;
  for (long long i = 0; i <= cnt; ++i) {
    if (mk[i]) {
      mk[i] = 2;
      memset(vst, 0, sizeof(vst));
      tot = 0;
      memset(dfn, 0, sizeof(dfn));
      memset(low, 0, sizeof(low));
      long long res1 = wt[i], res2 = INF, eg1 = i, eg2;
      tar(bg, -1, res2, eg2);
      if (!vst[fn]) res2 = 0, eg2 = -5;
      if (res1 + res2 < res) {
        res = res1 + res2;
        vt1 = eg1 / 2 + 1, vt2 = eg2 / 2 + 1;
      }
      mk[i] = 1;
    }
  }
  if (vt1 == -1) {
    cout << -1 << endl;
    return;
  }
  cout << res << endl;
  cout << (vt2 == -1 ? 1 : 2) << endl;
  cout << vt1 << " ";
  if (vt2 != -1) cout << vt2 << endl;
}
void work() {}
int main() {
  std::ios::sync_with_stdio(0);
  long long casenum;
  {
    init();
    work();
  }
  return 0;
}

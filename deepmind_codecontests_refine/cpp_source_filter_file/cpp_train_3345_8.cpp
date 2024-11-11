#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const long long INFF = (long long)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)1e6 + 7;
inline long long add(long long v1, long long v2) {
  v1 += v2;
  if (v1 >= mod) v1 -= mod;
  if (v1 < 0) v1 += mod;
  return v1;
}
struct Bit {
  long long num[MXN];
  long long a[MXN];
  void md(int p, int cnt, int v) {
    for (int i = p; i < MXN; i += (i & -i)) {
      num[i] += cnt;
      a[i] += cnt * 1ll * v;
    }
  }
  long long qy(long long sum) {
    int p = 0;
    long long v = 0;
    long long res = 0;
    for (int i = 20; i >= 0; i--) {
      int nxt = p ^ (1 << i);
      if (nxt > MXN) continue;
      if (v + a[nxt] > sum) continue;
      p = nxt;
      v += a[p];
      res += num[p];
    }
    if (p + 1 < MXN && num[p + 1]) res += (sum - v) / (p + 1);
    return res;
  }
} bit;
vector<pair<int, int> > edge[MXN];
int a[MXN], b[MXN];
long long val[MXN];
bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
  return val[u.first] > val[v.first];
}
void dfs(int u, long long dis) {
  bit.md(b[u], a[u], b[u]);
  val[u] = bit.qy(dis);
  for (pair<int, int> x : edge[u]) {
    if (x.second >= dis) continue;
    dfs(x.first, dis - x.second);
  }
  sort(begin(edge[u]), end(edge[u]), cmp);
  if (u == 1 && (int)(edge[u]).size() >= 1) {
    val[u] = max(val[u], val[edge[u][0].first]);
  } else if (u != 1 && (int)(edge[u]).size() >= 2) {
    val[u] = max(val[u], val[edge[u][1].first]);
  }
  bit.md(b[u], -a[u], b[u]);
  return;
}
int main(void) {
  int n;
  long long T;
  scanf("%d %lld", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  for (int i = 2; i <= n; i++) {
    int pa, d;
    scanf("%d %d", &pa, &d);
    edge[pa].push_back(make_pair(i, d));
  }
  dfs(1, T);
  printf("%lld\n", val[1]);
  return 0;
}

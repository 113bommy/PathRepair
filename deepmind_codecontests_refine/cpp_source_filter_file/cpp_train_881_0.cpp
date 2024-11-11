#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int maxn = 1e5 + 5;
int par[maxn], val[maxn];
void init(int n) {
  for (int i = 1; i <= n; i++) par[i] = i, val[i] = 0;
}
int find(int x) {
  if (par[x] == x) return x;
  int tmp = find(par[x]);
  val[x] ^= val[par[x]];
  return par[x] = tmp;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  init(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    int t1 = find(u), t2 = find(v);
    if (t1 != t2) {
      val[t2] = val[u] ^ val[v] ^ w;
      par[t2] = t1;
    } else {
      if (val[u] == val[v] && w == 1) {
        puts("0");
        return 0;
      }
      if (val[u] != val[v] && w == 0) {
        puts("0");
        return 0;
      }
    }
  }
  long long ans = (mod - mod / 2) % mod;
  for (int i = 1; i <= n; i++)
    if (find(i) == i) ans = (ans + ans) % mod;
  cout << ans << endl;
  return 0;
}

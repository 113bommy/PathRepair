#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 99, mod = 1e9 + 9;
int n, t, m, u, v, ans = 1, par[N];
int Get_Par(int u) {
  if (par[u] < 0) return u;
  return par[u] = Get_Par(par[u]);
}
void merge(int u, int v) {
  if ((u = Get_Par(u)) == (v = Get_Par(v))) {
    ans = ans * 2ll % mod;
    return;
  }
  if (par[u] > par[v]) swap(u, v);
  par[u] += par[v];
  par[v] = u;
}
int main() {
  fill(par, par + N, -1);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    ;
    merge(u, v);
    cout << ans - 1 << '\n';
  }
}

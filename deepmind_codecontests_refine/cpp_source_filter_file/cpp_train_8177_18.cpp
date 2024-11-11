#include <bits/stdc++.h>
using namespace std;
const int N = 4000 + 10, M = 500 * 1000 + 10, mod = 998244353;
bitset<N> a[N];
int x[M], y[M];
int id[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
    a[x[i]].set(y[i]);
  }
  for (int i = 0; i < n; i++) a[i][i + n] = 1;
  for (int i = 0; i < n; i++) id[i] = i;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++)
      if (a[id[j]][i]) {
        swap(id[i], id[j]);
        break;
      }
    for (int j = 0; j < n; j++)
      if (j != i && a[id[j]][i]) a[id[j]] ^= a[id[i]];
  }
  for (int i = 0; i < m; i++)
    cout << (a[y[i]][x[i] + n] ? "NO" : "YES") << '\n';
}

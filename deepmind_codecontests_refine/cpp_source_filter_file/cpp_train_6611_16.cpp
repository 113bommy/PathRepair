#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int f[N], b[N], c[N], a[N], v[N], g[N], h[N], d[N], l[N], p[N], o[N];
int n, m, y, x, fff;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> f[i];
  for (int i = 1; i <= n; i++) cin >> b[i], v[b[i]] = 1;
  for (int i = 1; i <= n; i++) {
    if (!c[f[i]])
      c[f[i]] = i;
    else if (v[f[i]])
      fff = 1;
  }
  for (int i = 1; i < N; i++) {
    if (v[i] && !c[i]) {
      cout << "Impossible";
      return 0;
    }
  }
  if (fff) {
    cout << "Ambiguity";
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 1; i <= m; i++) cout << c[b[i]] << " ";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long blok = 150;
long long dist[1003][1003], tambah[1003], n, d, x[1003], y[1003];
int main() {
  scanf("%lld%lld", &n, &d);
  for (int i = 2; i < n; i++) scanf("%lld", &tambah[i]);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &x[i], &y[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d - tambah[j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }
  cout << dist[1][n] << endl;
}

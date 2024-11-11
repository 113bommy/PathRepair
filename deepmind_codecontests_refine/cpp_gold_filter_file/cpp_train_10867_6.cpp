#include <bits/stdc++.h>
using namespace std;
long long n, d, a[101], x[101], y[101], D[101][101];
int main() {
  cin >> n >> d;
  for (int i = 2; i < n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) D[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[j];
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
  cout << D[1][n] << endl;
  return 0;
}

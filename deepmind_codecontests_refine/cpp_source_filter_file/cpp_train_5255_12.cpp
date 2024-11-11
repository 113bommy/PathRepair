#include <bits/stdc++.h>
using namespace std;
const int oo = int(1e9) + 7;
int w[150][150];
int a[150], b[150];
int g;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, m;
  cin >> n >> m;
  int maxw = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> w[i][j];
      maxw = max(maxw, w[i][j]);
    }
  for (int i = 1; i <= m; i++) b[i] = w[1][i];
  for (int i = 1; i <= n; i++) a[i] = w[i][1] - b[1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x = a[i] + b[j] - w[i][j];
      g = gcd(g, x);
    }
  g = abs(g);
  int K;
  if (g == 0)
    K = oo;
  else {
    if (g > maxw)
      K = g;
    else
      K = -1;
  }
  if (K == -1)
    cout << "NO";
  else {
    cout << "YES" << endl;
    cout << K << endl;
    for (int i = 1; i <= n; i++) cout << ((a[i] % K) + K) % K << ' ';
    cout << endl;
    for (int i = 1; i <= m; i++) cout << ((b[i] % K) + K) % K << ' ';
    cout << endl;
  }
}

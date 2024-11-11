#include <bits/stdc++.h>
using namespace std;
long long f[100], g[100][2], a[100];
int nn, n;
int main() {
  int tt;
  cin >> tt;
  for (tt = tt; tt > 0; tt--) {
    long long m;
    cin >> m;
    f[1] = 1;
    f[2] = 2;
    nn = 2;
    n = 0;
    for (int i = 3; f[i - 1] < m; i++, nn++) f[i] = f[i - 1] + f[i - 2];
    for (int i = nn; m > 0; i--)
      if (f[i] <= m) {
        m -= f[i];
        n++;
        a[n] = i;
      }
    g[n][1] = 1;
    g[n][0] = (a[n] - 1) / 2;
    for (int i = n - 1; i >= 1; i--) {
      g[i][1] = g[i + 1][0] + g[i + 1][1];
      g[i][0] = g[i + 1][0] * ((a[i] - a[i + 1]) / 2) +
                g[i + 1][1] * ((a[i] - a[i + 1] - 1) / 2);
    }
    cout << g[1][1] + g[1][0] << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
void read();
const int N = 1e5 + 100;
const int M = 3e5 + 100;
const long long oo = 1e18;
long long n, m, k, t, q, h, a, b, c, e, w, x, y, z;
using namespace std;
double gh[60][60];
int main() {
  cin >> n >> t;
  int ans = 0;
  while (t--) {
    gh[1][11] += 1;
    for (int i = 1; i <= 55; i++) {
      for (int j = 1; j <= 55; j++) {
        if (gh[i][j] <= 1) continue;
        gh[i + 1][j + 1] += (gh[i][j] - 1) / 2.0;
        gh[i + 1][j - 1] += (gh[i][j] - 1) / 2.0;
        gh[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 60; j++) {
      if (gh[i][j] == 1) ans++;
    }
  }
  cout << ans;
  return 0;
}

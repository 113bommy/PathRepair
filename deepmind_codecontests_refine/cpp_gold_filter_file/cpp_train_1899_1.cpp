#include <bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
long long d, m;
long long F[35][35];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> d >> m;
    int mx = log2(d);
    for (int i = 1; i <= 31; i++)
      for (int j = 0; j <= 30; j++) F[i][j] = 0;
    for (int j = 0; j <= 30; j++) {
      if (j > mx) break;
      if (j == mx)
        F[1][j] = (d - int(1 << j) + 1) % m;
      else
        F[1][j] = int(1 << j) % m;
    }
    for (int i = 2; i <= 31; i++) {
      for (int j = 1; j <= 30; j++) {
        if (j > mx) break;
        for (int k = 0; k <= j - 1; k++) {
          if (j == mx)
            F[i][j] = (F[i][j] + (F[i - 1][k] * (d - int(1 << j) + 1)) % m) % m;
          else
            F[i][j] = (F[i][j] + (F[i - 1][k] * int(1 << j)) % m) % m;
        }
      }
    }
    long long res = 0;
    for (int i = 1; i <= 31; i++)
      for (int j = 0; j <= 30; j++) res = (res + F[i][j]) % m;
    cout << res << '\n';
  }
}

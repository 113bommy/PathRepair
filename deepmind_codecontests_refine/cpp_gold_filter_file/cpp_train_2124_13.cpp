#include <bits/stdc++.h>
using namespace std;
long double pi = acos(-1);
long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
char board[101][101];
signed main() {
  ifstream in("Text.txt");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  long long k;
  int a, b;
  int t;
  cin >> n;
  if (n % 2 == 1) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= (n - 1) / 2; j++) {
        for (int k = 0; k < n - 2 * j; k++) {
          board[j][j + k] = ((i + j) % 2 ? 'b' : 'w');
          board[j + k][j] = ((i + j) % 2 ? 'b' : 'w');
        }
      }
      for (int j = 0; j < n; j++)
        for (int k = n - 1 - j; k < n; k++)
          board[j][k] = board[n - 1 - k][n - 1 - j];
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) cout << board[j][k];
        cout << endl;
      }
      cout << endl;
    }
  }
  return 0;
}

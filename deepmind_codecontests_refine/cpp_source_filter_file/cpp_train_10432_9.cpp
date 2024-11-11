#include <bits/stdc++.h>
long long int mod = 1000000000 + 7;
long long int inf = (long long int)(5e18);
using namespace std;
mt19937 unlucko(chrono::steady_clock::now().time_since_epoch().count());
int a[4][1000];
char mat[2000][2000];
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if ((mat[i][j] - '0') != (a[0][i] ^ a[1][j])) {
        a[0][i] ^= 1;
        a[1][j] ^= 1;
        ++ans;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if ((mat[j][i] - '0') != (a[2][j] ^ a[3][i])) {
        a[2][j] ^= 1;
        a[3][i] ^= 1;
        ++ans;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if ((mat[i][i] - '0') != (a[0][i] ^ a[3][i] ^ a[1][i] ^ a[2][i])) ++ans;
  }
  cout << ans;
}

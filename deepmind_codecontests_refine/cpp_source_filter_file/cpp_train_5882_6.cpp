#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
const long long mod = 1e9 + 7;
long long C[N][N], bell[N][N];
void cm(long long& x) {
  if (x >= mod) x -= mod;
}
void init() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      cm(C[i][j]);
    }
  }
  bell[1][1] = 1;
  for (int i = 2; i < N; ++i) {
    bell[i][1] = bell[i - 1][i - 1];
    for (int j = 2; j <= i; ++j) {
      bell[i][j] = bell[i][j - 1] + bell[i - 1][j - 1];
      cm(bell[i][j]);
    }
  }
}
int main() {
  init();
  long long ans = 0, n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    ans += C[n][i] * bell[n - i][n - i] % mod;
    cm(ans);
  }
  cout << ans << endl;
}

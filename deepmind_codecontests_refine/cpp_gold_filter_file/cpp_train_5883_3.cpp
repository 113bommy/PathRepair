#include <bits/stdc++.h>
using namespace std;
const int N = 4123, lgN = 20, rootN = 1123;
long long c[N][N], eq[N];
int main() {
  c[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= (i / 2); ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      if (c[i][j] >= 1000000007LL) c[i][j] -= 1000000007LL;
    }
    for (int j = (i / 2) + 1; j <= i; ++j) c[i][j] = c[i][i - j];
  }
  int n;
  cin >> n;
  eq[0] = 1;
  for (int i = 1; i <= n; ++i) {
    eq[i] = 0;
    for (int j = 1; j <= n; ++j) {
      eq[i] = (eq[i] + c[i - 1][j - 1] * eq[i - j]) % 1000000007LL;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + c[n][i] * eq[n - i]) % 1000000007LL;
  }
  cout << ans << "\n";
  return 0;
}

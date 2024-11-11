#include <bits/stdc++.h>
using namespace std;
const long long MXN = 4e4 + 10;
const long long MXK = 40;
long long a, b, n;
long long dp[MXN][MXK];
bool over(long long a, long long b) {
  long long res = 1;
  for (int i = 1; i <= b; i++) {
    res = res * a;
    if (res >= n) return 1;
  }
  return 0;
}
long long memo(long long a, long long b) {
  if (dp[a][b] != -1) return dp[a][b];
  if (a * a >= n && b == 1) {
    return dp[a][b] = (n - 1 - a) & 1LL;
  }
  dp[a][b] = 0;
  if (!over(a + 1, b) && !memo(a + 1, b)) dp[a][b] = 1;
  if (!over(a, b + 1) && !memo(a, b + 1)) dp[a][b] = 1;
  return dp[a][b];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> n;
  memset(dp, -1, sizeof dp);
  if (a == 1) {
    dp[a][MXK - 1] = 2;
    for (int i = MXK - 2; i; i--) {
      if (!over(a + 1, i) && !memo(a + 1, i)) {
        dp[a][i] = 1;
      } else {
        if (dp[a][i + 1] == 2)
          dp[a][i] = 2;
        else if (dp[a][i + 1] == 1)
          dp[a][i] = 0;
        else
          dp[a][i] = 1;
      }
    }
  }
  long long w = memo(a, b);
  if (dp[a][b] == 2) return cout << "Missing\n", 0;
  cout << (!dp[a][b] ? "Stas\n" : "Masha\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& a) {
  a = 0;
  char c;
  bool _MINUS_ = false;
  while (!isdigit(c = getchar())) _MINUS_ |= c == '-';
  do a = a * 10 + (c - '0');
  while (isdigit(c = getchar()));
  if (_MINUS_) a *= -1;
}
string world[8] = {"U", "D", "R", "L", "UL", "UR", "DR", "DL"};
const int rx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int ry[8] = {0, 0, 1, -1, -1, 1, 1, -1};
const long long mod = 1000000007;
long long step[19];
long long kek(long long n) {
  if (n == 0) return 0;
  if (n < 10) return 1;
  int len = 0;
  int last = 0;
  {
    long long n1 = n;
    while (n1 > 0) {
      len++;
      last = n % 10;
      n1 /= 10;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= len - 1; i++) ans += step[i - 1];
  if (last > 1) {
    ans += step[len - 1];
  } else {
    ans += n % step[len - 1] + 1;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  step[0] = 1;
  for (int i = 1; i <= 18; i++) step[i] = step[i - 1] * 10;
  int n;
  cin >> n;
  long double good[n];
  cout << fixed << setprecision(10);
  for (int i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    long long cnt = kek(r) - kek(l - 1);
    good[i] = 1.0 * cnt / (r - l + 1);
  }
  int k;
  cin >> k;
  long double dp[n + 1][n + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 0.0;
    }
  }
  dp[0][0] = 1.0;
  long double ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = (j > 0 ? good[i - 1] * dp[i - 1][j - 1] : 0.0) +
                 (1.0 - good[i - 1]) * dp[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++)
    if (1.0 * i / n >= k / 100.0) ans += dp[n][i];
  cout << ans;
  return 0;
}

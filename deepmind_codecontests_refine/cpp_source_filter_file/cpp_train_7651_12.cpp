#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar())) flag |= (ch == '-');
  x = ch - '0';
  while (isdigit(ch = getchar())) x = x * 10 + ch - '0';
  if (flag) x = -x;
}
int dp[37][37][57];
int main() {
  for (int i = 0; i <= 30; ++i)
    for (int j = 0; j <= 30; ++j)
      for (int k = 0; k <= 50; ++k) {
        dp[i][j][k] = INT_MAX >> 1;
        if (!k || k == i * j) {
          dp[i][j][k] = 0;
          continue;
        }
        for (int a = 0; a <= k; ++a) {
          for (int b = 1; b < j; ++b)
            dp[i][j][k] =
                min(dp[i][j][k], dp[i][b][a] + dp[i][j - b][k - a] + i * i);
          for (int b = 1; b < i; ++b)
            dp[i][j][k] =
                min(dp[i][j][k], dp[b][j][a] + dp[i - b][j][k - a] + j * j);
        }
      }
  int T;
  read(T);
  while (T--) {
    int a, b, c;
    read(a);
    read(b);
    read(c);
    cout << dp[a][b][c] << "\n";
  }
}

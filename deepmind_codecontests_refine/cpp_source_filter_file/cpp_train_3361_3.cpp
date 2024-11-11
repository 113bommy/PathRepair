#include <bits/stdc++.h>
using namespace std;
const int Size = 2e2 + 10;
const int INF = 0x3f3f3f3f;
int a[Size], dp[Size][2 * Size];
inline int read() {
  register int x = 0, f = 1;
  register char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c & 15);
    c = getchar();
  }
  return x * f;
}
int main() {
  int t = read();
  while (t--) {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < 2 * Size; i++) dp[0][i] = 0;
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j < Size; j++) {
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(a[i] - j));
      }
    }
    int minn = INF;
    for (int i = 0; i < Size; i++) minn = min(minn, dp[n][i]);
    printf("%d\n", minn);
  }
  return 0;
}

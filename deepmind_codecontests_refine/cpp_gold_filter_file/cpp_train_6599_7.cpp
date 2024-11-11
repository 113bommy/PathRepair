#include <bits/stdc++.h>
using namespace std;
int N;
unsigned int dp[110000];
char str[110000];
unsigned int Pow(unsigned int x, unsigned int y) {
  if (y == 0) return 1;
  unsigned int ans = Pow(x, y / 2);
  ans = ans * ans;
  if (y & 1) ans = ans * x;
  return ans;
}
int main() {
  scanf("%d%s", &N, str);
  if (N & 1) {
    puts("0");
    return 0;
  }
  int b = 0;
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    if (str[i] == '?') {
      b++;
      int mx = min(i + 2, N - i);
      unsigned int pre = 0;
      for (int j = 0; j < mx; j++) {
        unsigned int cur = dp[j];
        dp[j] = pre + dp[j + 1];
        pre = cur;
      }
    } else {
      b--;
      int mx = min(i + 1, N - i + 1);
      for (int j = mx; j > 0; j--) dp[j] = dp[j - 1];
      dp[0] = 0;
    }
  }
  unsigned int ans = dp[0] * Pow(25, b / 2);
  printf("%u\n", ans);
  return 0;
}

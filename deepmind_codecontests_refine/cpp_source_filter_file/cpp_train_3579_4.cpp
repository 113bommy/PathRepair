#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3;
int a[MAXN];
int dp[305][305];
int p_or_n(int i, int j) {
  for (int k = 0; k < i; ++k) {
    if (dp[k][j] == 1) {
      return 2;
    }
  }
  for (int k = 0; k < j; ++k) {
    if (dp[i][k] == 1) {
      return 2;
    }
  }
  for (int k = 0; k <= min(i, j); ++k) {
    if (dp[i - k][j - k] == 1) {
      return 2;
    }
  }
  return 1;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  if (n == 1) {
    puts(a[0] ? "BitAryo" : "BitLGM");
  } else if (n == 3) {
    puts(a[0] ^ a[1] ^ a[2] ? "BitLGM" : "BitAryo");
  } else {
    dp[0][0] = 1;
    for (int i = 0; i < 300; ++i) {
      for (int j = 0; j < 300; ++j) {
        if (dp[i][j] == 0) {
          dp[i][j] = p_or_n(i, j);
        }
      }
    }
    puts(dp[a[0]][a[1]] == 2 ? "BitLGM" : "BitAryo");
  }
  return 0;
}

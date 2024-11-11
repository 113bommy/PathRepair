#include <bits/stdc++.h>
using namespace std;
int T;
int n, k;
int a[2010];
int dp[2010][2010], mx[2010];
template <typename Tp>
void read(Tp &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
int main() {
  read(T);
  while (T--) {
    read(n), read(k);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        dp[i][j] = mx[i - j - 1] + (i - j == a[i]);
      }
      for (int j = 0; j <= i; j++) mx[j] = max(mx[j], dp[i][i - j]);
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (dp[n][i] >= k) {
        flag = true;
        printf("%d\n", i);
        break;
      }
    }
    if (!flag) printf("-1\n");
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < n; j++) dp[i][j] = mx[j] = 0;
  }
  return 0;
}

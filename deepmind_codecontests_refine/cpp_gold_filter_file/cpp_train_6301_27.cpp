#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[120000];
char str[120000];
bool fun(int v) {
  int i, x, y;
  for (i = 0; i < n; i++) {
    if (str[i] == '1') {
      continue;
    }
    x = i - v;
    y = i + v;
    if (x <= 0) {
      x = 0;
    } else {
      x = dp[x - 1];
    }
    if (y >= n) {
      y = dp[n - 1];
    } else {
      y = dp[y];
    }
    if (y - x > k) {
      return true;
    }
  }
  return false;
}
void solve() {
  int i, j = 0;
  for (i = 0; i < n; i++) {
    if (str[i] == '0') {
      j++;
    }
    dp[i] = j;
  }
  int x = 0;
  int y = n;
  int mid;
  while (x < y) {
    mid = (x + y) / 2;
    if (fun(mid)) {
      y = mid;
    } else {
      x = mid + 1;
    }
  }
  printf("%d\n", x);
}
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    scanf("%s", &str);
    solve();
  }
  return 0;
}

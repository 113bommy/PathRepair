#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, d, n;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
  vector<int> ar(n);
  for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
  vector<vector<char>> dp(max(b, d));
  for (int i = 0; i < max(b, d); i++) dp[i].resize(a + c);
  if (b > d) {
    for (int i = a; i < a + c; i++) {
      for (int j = d; j < b; j++) {
        dp[j][i] = '.';
      }
    }
  } else {
    for (int i = 0; i < a; i++) {
      for (int j = b; j < d; j++) {
        dp[j][i] = '.';
      }
    }
  }
  int k = 0, j;
  char ch = char('a' + 0);
  int len = ar[0];
  for (int i = 0; i < a; i++) {
    if ((a & 1 && i && 1) || (a % 2 == 0 && i % 2 == 0)) {
      for (j = 0; j < b; j++) {
        if (len == 0) {
          k++;
          ch = char(k + 'a');
          len = ar[k];
        }
        dp[j][i] = ch;
        len--;
      }
    } else {
      for (int j = b - 1; j >= 0; j--) {
        if (len == 0) {
          k++;
          ch = char(k + 'a');
          len = ar[k];
        }
        dp[j][i] = ch;
        len--;
      }
    }
  }
  bool val = 1;
  for (int i = a; i < a + c; i++) {
    if (val) {
      for (j = 0; j < d; j++) {
        if (len == 0) {
          k++;
          ch = char(k + 'a');
          len = ar[k];
        }
        dp[j][i] = ch;
        len--;
      }
      val = 1 - val;
    } else {
      for (j = d - 1; j >= 0; j--) {
        if (len == 0) {
          k++;
          ch = char(k + 'a');
          len = ar[k];
        }
        dp[j][i] = ch;
        len--;
      }
      val = 1 - val;
    }
  }
  puts("YES");
  for (int i = 0; i < max(b, d); i++) {
    for (j = 0; j < a + c; j++) {
      printf("%c", dp[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}

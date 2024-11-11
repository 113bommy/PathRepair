#include <bits/stdc++.h>
using namespace std;
int a[2005][2005];
int64_t dpt[2005];
void dp(int n, string s) {
  for (int i = 0; i < n; i++) {
    a[i][i] = 1;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < n - l + 1; i++) {
      if (s[i] == s[i + l - 1]) {
        if (l == 2 || a[i + 1][i + l - 2]) {
          a[i][i + l - 1] = 1;
        }
      }
    }
  }
}
int main() {
  string s;
  cin >> s;
  int n = s.length();
  dp(n, s);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (a[i - 1][j - 1]) {
        dpt[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    dpt[i] += dpt[i - 1];
  }
  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (a[i - 1][j - 1]) {
        ans += dpt[i - 1];
      }
    }
  }
  cout << ans;
}

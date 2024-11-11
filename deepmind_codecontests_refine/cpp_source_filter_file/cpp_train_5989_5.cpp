#include <bits/stdc++.h>
using namespace std;
int binomial_coefficient(int n, int k) {
  if (n < k) return 0;
  int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; i++) {
    res *= n - i;
    res /= k - i;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  char s[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> s[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int flag = 0;
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'C') flag++;
    }
    ans += binomial_coefficient(flag, 2);
  }
  for (int j = 0; j < n; ++j) {
    int flag = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == 'C') flag++;
    }
    ans += binomial_coefficient(flag, 2);
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
char s[555555];
int n;
double dp[555555], w[555555], W = 0.0;
int main() {
  cin >> s;
  n = strlen(s);
  w[1] = 1.0;
  for (int i = 2; i <= n + 1; i++) {
    w[i] = w[i - 1] + 1.0 / (i * 1.0);
  }
  dp[0] = w[n];
  for (int i = 1; i < n; i++) dp[i] = dp[i - 1] + w[n - i + 1] - w[i + 1];
  for (int i = 0; i < n; i++)
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y')
      W += dp[i];
  printf("%.7lf", W);
  return 0;
}

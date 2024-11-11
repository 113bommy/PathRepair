#include <bits/stdc++.h>
using namespace std;
const int max_n = 20;
int a[2 * max_n];
long long _10[max_n];
long long ind[max_n];
long long dp[max_n];
int main() {
  int n;
  cin >> n;
  _10[0] = 1;
  for (int i = 1; i <= n; i++) _10[i] = _10[i - 1] * 10;
  for (int i = 0; i < 2 * n; i++) {
    char x;
    cin >> x;
    a[i] = x - '0';
  }
  for (int i = 0; i <= n; i++) dp[i] = -1;
  for (int i = 0; i < (1 << n); i++) {
    long long num1 = 0;
    long long num2 = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j))
        num1 = num1 * 10 + a[j + n], cnt++;
      else
        num2 = num2 * 10 + a[j + n];
    if (num1 + num2 > dp[cnt]) dp[cnt] = num1 + num2, ind[cnt] = i;
  }
  long long ans = -1;
  long long indf = 0, inds = 0;
  for (int i = 0; i < (1 << n); i++) {
    long long num1 = 0;
    long long num2 = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        num1 = num1 * 10 + a[j], cnt++;
      else
        num2 = num2 * 10 + a[j];
    }
    if (ans < num1 * _10[n - cnt] + num2 * _10[cnt] + dp[n - cnt]) {
      indf = i, inds = ind[n - cnt];
    }
    ans = max(ans, num1 * _10[n - cnt] + num2 * _10[cnt] + dp[n - cnt]);
  }
  for (int i = 0; i < n; i++) {
    if (indf & (1 << i))
      cout << "H";
    else
      cout << "M";
  }
  for (int i = 0; i < n; i++)
    if (inds & (1 << i))
      cout << "H";
    else
      cout << "M";
  return 0;
}

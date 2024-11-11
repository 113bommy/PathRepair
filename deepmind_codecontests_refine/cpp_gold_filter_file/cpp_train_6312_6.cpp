#include <bits/stdc++.h>
using namespace std;
long long int cons;
long long int check(long long int a) {
  if (a >= cons) a %= cons;
  return a;
}
long long int check2(long long int a) {
  if (a > 0) return a;
  long long int b = a / cons;
  a -= b * cons;
  if (a < 0) a += cons;
  return a;
}
long long int GCD(long long int a, long long int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
long long int exp(long long int a, long long int n) {
  if (n == 0) return 1;
  if (n == 1) return check(a);
  long long int b = exp(a, n / 2);
  if (n % 2 == 0) return check(b * b);
  return check(b * check(b * a));
}
long long int dp[40 * 100005 + 5];
int lim = 4e6;
long long int solve(int val) {
  if (val <= lim) return dp[val];
  long long int temp_ans = exp(2, val - 1);
  temp_ans--;
  if (temp_ans < 0) temp_ans += cons;
  for (int i = 2; i * i <= val; i++) {
    if (val % i == 0) {
      int temp = val / i;
      temp_ans -= solve(i);
      if (temp_ans < 0) temp_ans += cons;
      if (i != temp) temp_ans -= solve(temp);
      if (temp_ans < 0) temp_ans += cons;
    }
  }
  return temp_ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cons = 1e9 + 7;
  long long int two = 2;
  dp[1] = 1;
  for (int i = 2; i <= lim; i++) {
    dp[i] = two - 1;
    if (dp[i] < 0) dp[i] += cons;
    two = two << 1;
    if (two >= cons) two -= cons;
  }
  for (int i = 2; i <= lim; i++) {
    for (int j = i + i; j <= lim; j += i) {
      dp[j] -= dp[i];
      if (dp[j] < 0) dp[j] += cons;
    }
  }
  long long int first, second;
  cin >> first >> second;
  if (second % first != 0)
    cout << 0;
  else
    cout << solve(second / first);
}

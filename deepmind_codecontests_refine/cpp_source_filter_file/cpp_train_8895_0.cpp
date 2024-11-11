#include <bits/stdc++.h>
using namespace std;
string a, b;
double dp[21][21];
int mod = 1e9 + 7;
int main() {
  int a, b;
  cin >> a >> b;
  long long sum1 = (a * (a + 1)) / 2;
  sum1 = sum1 % mod;
  sum1 *= b;
  sum1 = sum1 % mod;
  sum1 += a;
  sum1 = sum1 % mod;
  long long sum2 = (b * (b - 1)) / 2;
  sum2 = sum2 % mod;
  sum1 *= sum2;
  sum1 = sum1 % mod;
  cout << sum1;
  return 0;
}

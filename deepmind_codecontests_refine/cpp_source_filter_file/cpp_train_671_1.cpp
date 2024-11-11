#include <bits/stdc++.h>
const long long INF = 1e9;
const long long lINF = 1e18;
const double EPS = 1e-12;
const int MOD = 1e9 + 7;
using namespace std;
int n, k;
string num;
long long ck[111111], ck1[111111], sum[111111];
long long power(long long a, int p) {
  long long ans = 1;
  while (p) {
    if (p & 1) {
      ans = (ans * a) % MOD;
    }
    p >>= 1;
    a = (a * a) % MOD;
  }
  return ans;
}
int main() {
  cin >> n >> k;
  cin >> num;
  if (k == 0) {
    for (int i = 0; i <= n + 10; i++) {
      ck[i] = 1;
    }
  } else if (k == 1) {
    ck1[0] = 1;
    for (int i = k; i < n + 10; i++) {
      ck[i] = i;
      ck1[i] = 1;
    }
  } else {
    ck[k] = 1;
    ck1[k - 1] = 1;
    for (int i = k + 1; i < n + 10; i++) {
      ck[i] = ((ck[i - 1] * i) % MOD * power(i - k, MOD - 2)) % MOD;
    }
    for (int i = k; i < n + 10; i++) {
      ck1[i] = ((ck1[i - 1] * i) % MOD * power(i - k, MOD - 2)) % MOD;
    }
  }
  for (int i = k - 1; i < n - 2; i++) {
    ck1[i] = (ck1[i] * power(10, n - 2 - i)) % MOD;
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = (sum[i - 1] + ck1[n - 1 - i]) % MOD;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + ((num[i] - '0') * ck[i]) % MOD * power(10, n - i - 1)) % MOD;
    ans = (ans + (num[i] - '0') * sum[n - 1 - i]) % MOD;
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 500007;
stack<long long> s;
long long a[N];
long long f[N];
long long sum[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  s.push(0);
  f[0] = 1;
  sum[0] = 1;
  long long ans;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      long long pos = s.top();
      s.pop();
      if (s.empty()) {
        ans = (ans - a[pos] * sum[pos - 1] % mod + mod) % mod;
      } else {
        ans = (ans - a[pos] * (sum[pos - 1] - sum[s.top() - 1] + mod) % mod +
               mod) %
              mod;
      }
    }
    if (s.empty()) {
      ans = (ans + a[i] * sum[i - 1] % mod) % mod;
    } else {
      ans = (ans + a[i] * ((sum[i - 1] - sum[s.top() - 1] + mod) % mod) % mod) %
            mod;
    }
    s.push(i);
    if (i % 2 == 1) {
      f[i] = ans;
    } else {
      f[i] = (mod - ans) % mod;
    }
    if (i % 2 == 1) {
      f[i] = (mod - f[i]) % mod;
    }
    sum[i] = (f[i] + sum[i - 1]) % mod;
  }
  if (n % 2 == 1) {
    printf("%lld\n", (mod - f[n]) % mod);
  } else {
    printf("%lld\n", f[n]);
  }
  return 0;
}

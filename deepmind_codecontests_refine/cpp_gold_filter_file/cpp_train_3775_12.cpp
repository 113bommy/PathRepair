#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
const int mod = 998244353;
int c[maxn], sum[maxn];
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }
int mul(int a, int b) { return 1ll * a * b % mod; }
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  long long invn = qpow(n, mod - 2);
  sort(c + 1, c + 1 + n, greater<int>());
  for (int i = 1; i <= n; ++i) {
    sum[i] = add(sum[i - 1], c[i]);
  }
  for (int i = 1; i <= n / 2; ++i) {
    int ans = 0, tmp = (n - i) / i + ((n - i) % i != 0);
    for (int j = 2;; ++j) {
      if (j <= tmp) {
        ans = add(ans, mul(sub(sum[j * i], sum[(j - 1) * i]), j - 1));
      } else {
        ans = add(ans, mul(sub(sum[n], sum[(j - 1) * i]), j - 1));
        break;
      }
    }
    printf("%d ", mul(ans, invn));
  }
  for (int i = n / 2 + 1; i <= n; ++i) {
    printf("%d%c", mul(sub(sum[n], sum[i]), invn), " \n"[i == n]);
  }
}

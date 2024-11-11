#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 500;
long long A[maxn], A_ni[maxn], inv[maxn];
void pre(long long mod) {
  A[0] = A_ni[0] = A[1] = A_ni[1] = inv[1] = 1;
  for (int i = 2; i < maxn; i++) A[i] = A[i - 1] * i % mod;
  for (int i = 2; i < maxn; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i < maxn; i++) A_ni[i] = A_ni[i - 1] * inv[i] % mod;
}
long long C(long long n, long long m, long long mod) {
  return A[n] * A_ni[m] % mod * A_ni[n - m] % mod;
}
long long ksm(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long tim[maxn], sum[maxn];
int main() {
  long long n, m, a, q;
  cin >> n >> m >> a >> q;
  long long x = 1, now = a % q;
  while (now != 1) {
    now = now * a % q;
    x++;
  }
  pre(x);
  for (int i = 1; i <= m + 1; i++) {
    tim[i] = (tim[i - 1] + C(m, i - 1, x)) % x;
  }
  for (int i = n; i >= 1; i--) {
    int index = n - i + 1;
    if (index <= m + 1)
      sum[i] = ksm(a, tim[index], q);
    else
      sum[i] = sum[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld", sum[i]);
    if (i != n) printf(" ");
  }
  puts("");
  return 0;
}

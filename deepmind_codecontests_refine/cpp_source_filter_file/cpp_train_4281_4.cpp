#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const long long mod = 1e9 + 7;
const int N = 1e5 + 10;
char s[N];
long long sum[N], a[N];
int main() {
  int n, q;
  cin >> n >> q;
  cin >> s + 1;
  a[0] = 1;
  for (int i = 1; i <= n; ++i) a[i] = a[i - 1] * 2;
  for (int i = 1; i <= (n); ++i) {
    sum[i] = sum[i - 1] + s[i] - '0';
  }
  int l, r;
  while (q--) {
    cin >> l >> r;
    int one = sum[r] - sum[l - 1];
    int zero = r - l + 1 - one;
    long long ans = ((a[r - l + 1] - a[zero]) % mod + mod) % mod;
    printf("%lld\n", ans);
  }
}

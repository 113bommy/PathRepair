#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2000010;
int read() {
  char c = getchar();
  int d = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; d = d * 10 - 48 + c, c = getchar())
    ;
  return d * f;
}
int mi(int a, int b) {
  int s = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) s = (long long)s * a % mod;
  return s;
}
int n, m, a, b, ft[N + 1], Ft[N + 1];
int C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return (long long)ft[a] * Ft[b] % mod * Ft[a - b] % mod;
}
int mul(int a, int b) { return (long long)a * b % mod; }
void inc(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  ft[0] = 1;
  for (int i = 1; i <= N; ++i) ft[i] = (long long)ft[i - 1] * i % mod;
  Ft[N] = mi(ft[N], mod - 2);
  for (int i = N; i >= 1; --i) Ft[i - 1] = (long long)Ft[i] * i % mod;
  cin >> n >> m >> a >> b;
  int ans = 0;
  for (int i = 2; i <= min(n, m + 1); ++i) {
    int s = mul(C(m - 1, i - 2), C(n - 2, i - 2));
    if (!s) continue;
    s = mul(s, ft[i - 2]);
    s = mul(s, mi(m, n - i));
    if (i < n) s = mul(s, mul(mi(n, n - i - 1), i));
    inc(ans, s);
  }
  cout << ans << endl;
}

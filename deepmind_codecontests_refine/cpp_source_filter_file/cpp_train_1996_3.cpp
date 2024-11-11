#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
inline long long add(long long a, long long b) {
  a += b;
  if (a >= mod) return a - mod;
  return a;
}
inline long long mul(long long a, long long b) {
  a *= b;
  if (a >= mod) return a % mod;
  return a;
}
inline long long power(long long a, long long b) {
  long long p = 1;
  while (b) {
    if (b & 1) p = mul(p, a);
    a = mul(a, a);
    b /= 2;
  }
  return p;
}
const int N = 3e5 + 5;
long long F[N];
long long IF[N];
long long C(int x, int y) {
  if (y < 0 || x < y) return 0;
  if (x == y || y == 0) return 1;
  return mul(mul(IF[y], IF[x - y]), F[x]);
}
long long get(long long pre, long long up, long long n, long long at) {
  if (at < 0) return 0;
  if (at == 0) return 1;
  if (at >= n) return power(2, n);
  for (int j = up; j > at; j--) {
    pre = add(pre, mod - C(n - 1, j));
  }
  pre = mul(pre, 2);
  pre = add(pre, mod - C(n - 1, up));
  return pre;
}
void init() {
  F[0] = 1;
  for (int i = 1; i < N; i++) {
    F[i] = mul(F[i - 1], i);
  }
  IF[N - 1] = power(F[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    IF[i] = mul(IF[i + 1], i + 1);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  long long n, T;
  cin >> n >> T;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) a[i] += a[i - 1];
  }
  long long ans = 0, pre = 1, up = 0, inv2 = power(2, mod - 2);
  for (long long i = 0; i < n; i++) {
    if (a[i] > T) break;
    long long hadaksar = min(i + 1, T - a[i]);
    long long val = get(pre, up, i + 1, hadaksar);
    ans = add(ans, mul(val, power(inv2, i + 1)));
    up = hadaksar;
    pre = val;
  }
  cout << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long pow(long long a, long long b, long long M) {
  long long t = 1;
  for (a %= M; b; b >>= 1) {
    if (b & 1) t = t * a % M;
    a = a * a % M;
  }
  return t;
}
inline int getc() {
  static const int N = 222;
  static char buf[N];
  static int n = 0, p = 0;
  if (p == n) p = 0, n = fread(buf, 1, N, stdin);
  if (p == n) exit(0);
  return buf[p++];
}
inline int R(int& first) {
  int f = 1, c = getc();
  first = 0;
  while (c <= 32) c = getc();
  if (c == '-') f = -1, c = getc();
  for (; '0' <= c && c <= '9'; c = getc()) first = first * 10 + c - '0';
  first *= f;
}
static const int N = 5e6, M = N + 5;
struct Sieve {
  int p[M], m, v[M];
  Sieve() {
    for (int i = 2; i <= int(N); i++) {
      if (!v[i]) p[++m] = i;
      for (int j = 1; j <= int(m); j++) {
        int k = i * p[j];
        if (k > N) break;
        v[k] = 1;
        if (i % p[j] == 0) break;
      }
    }
  }
  bool operator()(int i) { return !v[i]; }
} isprime;
int s[M];
map<long long, long long> q[M];
long long f(long long p, long long n) {
  if (p <= 1) return n - 1;
  if (q[p].count(n)) return q[p][n];
  if (n <= N && p * p >= n) return s[n];
  if (!isprime(p) || p * p > n)
    return f(p - 1, n);
  else
    return f(p - 1, n) - (f(p - 1, n / p) - f(p - 1, p - 1));
}
int main() {
  for (int i = 2; i <= int(N); i++) s[i] = s[i - 1] + isprime(i);
  long long n;
  cin >> n;
  long long ans = s[(int)(powl(n, 1.0 / 3) + 1e-5)];
  long long m = sqrt(n);
  for (int i = 2; i <= int(m); i++)
    if (isprime(i)) {
      long long t = n / i;
      ans += f(sqrt(t) + 1, t) - s[i];
    }
  cout << ans << endl;
}

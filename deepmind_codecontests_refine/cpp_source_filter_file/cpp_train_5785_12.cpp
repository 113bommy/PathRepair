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
const int N = 4e5 + 5, M = 1e9 + 7;
struct Comb {
  int n, f[N + 5], inv[N + 5];
  Comb() {
    f[0] = f[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= int(N); i++)
      inv[i] = 1LL * (M - M / i) * inv[M % i] % M;
    for (int i = 2; i <= int(N); i++) {
      f[i] = 1LL * i * f[i - 1] % M;
      inv[i] = 1LL * inv[i - 1] * inv[i] % M;
    }
  }
  long long C(int n, int m) {
    if (n < m || m < 0) return 0;
    return 1LL * f[n] * inv[m] % M * inv[n - m] % M;
  }
  int lucas(int n, int m) {
    if (n < M) return C(n, m);
    return 1LL * lucas(n / M, m / M) * lucas(n % M, m % M) % M;
  }
  int operator()(int n, int m) { return lucas(n, m); }
} C;
const int K = 2005;
pair<int, int> a[K];
int n, m, k, s, f[K][25];
int main() {
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= int(k); i++)
    scanf("%d", &a[i].first), scanf("%d", &a[i].second);
  a[++k] = make_pair(1, 1);
  a[++k] = make_pair(n, m);
  sort(a + 1, a + k + 1);
  f[1][1] = 1;
  for (int i = 2; i <= int(k); i++) {
    int sum = C(a[i].first + a[i].second - 2, a[i].first - 1);
    for (int p = 1; p <= int(24); p++) {
      f[i][p] = sum;
      for (int j = 1; j <= int(i - 1); j++) {
        if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
          (f[i][p] -= f[j][p] *
                      C(a[i].first - a[j].first + a[i].second - a[j].second,
                        a[i].first - a[j].first) %
                      M) %= M;
        }
      }
      (sum -= f[i][p]) %= M;
    }
  }
  int sum = C(n + m - 2, n - 1);
  int ans = 0;
  for (int i = 2; i <= int(24); i++) {
    (ans += 1LL * f[k][i] * s % M) %= M;
    (sum -= f[k][i]) %= M;
    s = (s + 1) / 2;
  }
  (ans += sum) %= M;
  sum = C(n + m - 2, n - 1);
  ans = ans * pow(sum, M - 2, M) % M;
  cout << (ans + M) % M << endl;
}

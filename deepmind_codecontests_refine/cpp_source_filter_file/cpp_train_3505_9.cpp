#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const double PI = acos(-1);
template <class A, class B>
std::ostream& operator<<(std::ostream& st, const std::pair<A, B> p) {
  st << "(" << p.first << ", " << p.second << ")";
  return st;
}
void tc();
auto test_cases = []() {
  int T;
  scanf("%d", &T);
  while (T--) tc();
};
using namespace std;
const int B = 20;
using ld = long double;
using point = complex<ld>;
using poly = point[1 << 20];
void fft(poly& f, int n, bool inv) {
  static poly W;
  for (int i = 1, j = 0; i + 1 < n; i++) {
    for (int k = n >> 1; !(k & (j ^= k)); k >>= 1)
      ;
    if (i < j) swap(f[i], f[j]);
  }
  for (int m = 1, k = 0; 2 * m <= n; m <<= 1, k++) {
    ld theta = PI / m * (2 * inv - 1);
    for (int i = 0; i < m; i++) W[i] = polar((ld)1.0, i * theta);
    for (int s = 0; s < n; s += 2 * m) {
      for (int i = 0; i < m; i++) {
        point a = f[s + i], b = f[s + i + m];
        f[s + i] = a + W[i] * b;
        f[s + i + m] = a - W[i] * b;
      }
    }
  }
  if (inv) {
    for (int i = 0; i < (n); i++) f[i] /= n;
  }
}
poly f, g;
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  std::vector<int> cnt(n + 1, 0);
  int s = 0;
  cnt[0] = 1;
  long long zero = 0, len = 0;
  for (int i = 0; i < (n); i++) {
    int v;
    scanf("%d", &v);
    s += v < x;
    cnt[s]++;
    if (v < x) {
      len = 0;
    } else {
      len++;
    }
    zero += len;
  }
  for (int i = 0; i <= n; i++) {
    f[i] = cnt[i];
    g[i] = cnt[n - i];
  }
  int N = n;
  while (N != ((N) & (-(N)))) N++;
  N <<= 1;
  fft(f, N, false);
  fft(g, N, false);
  for (int i = 0; i < (N); i++) f[i] *= g[i];
  fft(f, N, true);
  for (int k = 0; k <= n; k++) {
    long long v = round(f[k + n].real());
    if (k == 0) v = zero;
    printf("%lld%c", v, " \n"[k == n]);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline void read(int *a, int n) {
  for (int i = 0; i < n; i++) a[i] = in();
}
inline void readL(int *a, int n) {
  for (int i = 0; i < n; i++) a[i] = lin();
}
const int maxn = (1 << 23);
const int mod = 1e9 + 7;
const int MAX_VAL = 1e18 + 10;
const int MAGIC = 350;
int n, m, LG;
struct pt {
  double real, imag;
  pt(double real = 0, double imag = 0) : real(real), imag(imag) {}
  inline pt operator+(pt b) { return {real + b.real, imag + b.imag}; }
  inline pt operator-(pt b) { return {real - b.real, imag - b.imag}; };
  inline pt operator*(pt b) {
    return {real * b.real - imag * b.imag, real * b.imag + imag * b.real};
  };
} a[maxn];
inline void fft(pt *a, bool inverse) {
  for (int mask = 0; mask < n; mask++) {
    int revMask = 0;
    for (int j = 0; j < LG; j++) {
      if (mask >> j & 1) revMask ^= (1 << (LG - 1 - j));
    }
    if (mask < revMask) swap(a[mask], a[revMask]);
  }
  for (int N = 2; N <= n; N *= 2) {
    double angle = 2.0 * acos(-1) / N;
    if (inverse) angle *= -1.0;
    pt wn = {cos(angle), sin(angle)};
    for (int i = 0; i < n; i += N) {
      pt w = {1, 0};
      for (int j = 0; j < N / 2; j++) {
        pt Const = w * a[i + j + N / 2];
        pt A = a[i + j] + Const;
        pt B = a[i + j] - Const;
        a[i + j] = A, a[i + j + N / 2] = B;
        w = w * wn;
      }
    }
  }
  if (inverse)
    for (int i = 0; i < n; i++) a[i].real /= n, a[i].imag /= n;
}
bool have[maxn];
int32_t main() {
  n = in(), m = in();
  for (int i = 0; i < n; i++) {
    int foo = in();
    have[foo] = true;
    a[foo] = {1, 0};
  }
  n = 1;
  while (n < 2 * m) n *= 2, LG++;
  fft(a, 0);
  for (int i = 0; i < n; i++) a[i] = a[i] * a[i];
  fft(a, 1);
  vector<int> ans;
  for (int i = 1; i <= m; i++) {
    if (a[i].real > 0.9 && !have[i]) return cout << "NO\n", 0;
    if (have[i] && a[i].real < 0.9) ans.push_back(i);
  }
  cout << "YES\n";
  cout << ans.size() << "\n";
  for (auto x : ans) cout << x << " ";
}

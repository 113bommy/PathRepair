#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
const double PI = acos(-1.0);
struct Complex {
  double x, y;
  Complex() {}
  Complex(double a) : x(a), y(0) {}
  Complex(double a, double b) : x(a), y(b) {}
  Complex operator+(const Complex &a) { return Complex(x + a.x, y + a.y); }
  Complex operator-(const Complex &a) { return Complex(x - a.x, y - a.y); }
  Complex operator*(const Complex &a) {
    return Complex(x * a.x - y * a.y, x * a.y + y * a.x);
  }
};
inline vector<Complex> fft(vector<Complex> rtn, int Rev = 1) {
  int fft_n = rtn.size();
  for (int i = 0, j = 0; i < fft_n; i++) {
    if (i > j) swap(rtn[i], rtn[j]);
    for (int k = (fft_n >> 1); (j ^= k) < k; k >>= 1)
      ;
  }
  for (int i = 2, m; i <= fft_n; i <<= 1) {
    m = i >> 1;
    for (int j = 0; j < fft_n; j += i) {
      Complex w(1, 0), wn(cos(2 * PI / i), Rev * sin(2 * PI / i));
      for (int k = 0; k < m; k++) {
        Complex y = rtn[j + k + m] * w;
        rtn[j + k + m] = rtn[j + k] - y;
        rtn[j + k] = rtn[j + k] + y;
        w = w * wn;
      }
    }
  }
  for (int i = 0; ~Rev && i < fft_n; i++) rtn[i].x = rtn[i].x / fft_n;
  return rtn;
}
int n, m, k;
int N = 1;
char s[MAX_N], t[MAX_N];
vector<Complex> a, b;
int ans[MAX_N];
int tot;
inline void conv(char now) {
  a = b = vector<Complex>(N, 0);
  for (int i = 0, j = 0; i < n && j < n; i++) {
    while ((s[j] && s[j] != now) || i - j > k) j++;
    if (s[j] == now && abs(i - j) <= k) a[i] = 1;
  }
  for (int i = 0; i < m; i++)
    if (t[i] == now) b[i] = 1;
  a = fft(a);
  b = fft(b);
  for (int i = 0; i < N; i++) a[i] = a[i] * b[i];
  a = fft(a, -1);
  for (int i = m - 1; i < n + m - 1; i++) ans[i - m + 1] += int(a[i].x + 0.1);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  while (N < n + m - 1) N <<= 1;
  scanf("%s", s);
  scanf("%s", t);
  for (int i = 0; i < m / 2; i++) swap(t[i], t[m - i - 1]);
  conv('A');
  conv('T');
  conv('G');
  conv('C');
  for (int i = 0; i < n; i++)
    if (ans[i] == m) tot++;
  printf("%d\n", tot);
  return 0;
}

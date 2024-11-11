#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void arquivo() {
  freopen("", "r", stdin);
  freopen("", "w", stdout);
}
using namespace std;
const double PI = acos(-1.0);
struct Complex {
  double real, image;
  Complex(double _real, double _image) {
    real = _real;
    image = _image;
  }
  Complex() {}
};
Complex operator+(const Complex &c1, const Complex &c2) {
  return Complex(c1.real + c2.real, c1.image + c2.image);
}
Complex operator-(const Complex &c1, const Complex &c2) {
  return Complex(c1.real - c2.real, c1.image - c2.image);
}
Complex operator*(const Complex &c1, const Complex &c2) {
  return Complex(c1.real * c2.real - c1.image * c2.image,
                 c1.real * c2.image + c1.image * c2.real);
}
int rev(int id, int len) {
  int ret = 0;
  for (int i = 0; (1 << i) < len; i++) {
    ret <<= 1;
    if (id & (1 << i)) ret |= 1;
  }
  return ret;
}
Complex A[1 << 21];
void FFT(vector<Complex> &a, int DFT) {
  int len = a.size();
  for (int i = 0; i < len; i++) A[rev(i, len)] = a[i];
  for (int s = 1; (1 << s) <= len; s++) {
    int m = (1 << s);
    Complex wm = Complex(cos(DFT * 2 * PI / m), sin(DFT * 2 * PI / m));
    for (int k = 0; k < len; k += m) {
      Complex w = Complex(1, 0);
      for (int j = 0; j < (m >> 1); j++) {
        Complex t = w * A[k + j + (m >> 1)];
        Complex u = A[k + j];
        A[k + j] = u + t;
        A[k + j + (m >> 1)] = u - t;
        w = w * wm;
      }
    }
  }
  if (DFT == -1)
    for (int i = 0; i < len; i++) A[i].real /= len, A[i].image /= len;
  for (int i = 0; i < len; i++) a[i] = A[i];
  return;
}
vector<long long> mul(vector<long long> &a, vector<long long> &b) {
  vector<Complex> aa, bb;
  for (int i = 0; i < a.size(); ++i) {
    aa.push_back(Complex(a[i], 0.0));
  }
  for (int i = 0; i < b.size(); ++i) {
    bb.push_back(Complex(b[i], 0.0));
  }
  int n = 1;
  while (n < a.size() || n < b.size()) n <<= 1;
  n <<= 1;
  while (aa.size() < n) aa.push_back(Complex(0.0, 0.0));
  while (bb.size() < n) bb.push_back(Complex(0.0, 0.0));
  FFT(aa, 1);
  FFT(bb, 1);
  for (int i = 0; i < aa.size(); ++i) aa[i] = aa[i] * bb[i];
  FFT(aa, -1);
  vector<long long> res;
  for (int i = 0; i < n; i++) res.push_back(int(aa[i].real + 0.5));
  return res;
}
const int N = 500010;
int k, n, m;
char str1[N], str2[N];
long long cnt[N];
void solve(char x) {
  vector<long long> a(n, 0);
  vector<long long> b(m, 0);
  for (int i = 0; i < n; ++i)
    if (x == str1[i]) {
      a[max(0, i - k)]++;
      a[min(n - 1, i + k + 1)]--;
    }
  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
  }
  for (int i = 0; i < n; ++i) a[i] = min(a[i], 1LL);
  for (int i = 0; i < m; ++i)
    if (x == str2[i]) {
      b[m - i - 1]++;
    }
  vector<long long> c = mul(a, b);
  for (int i = 0; i < n - m + 1; i++) cnt[i] += c[m + i - 1];
}
inline void main2() {
  scanf("%d %d %d", &n, &m, &k);
  scanf(" %s", str1);
  scanf(" %s", str2);
  solve('A');
  solve('C');
  solve('G');
  solve('T');
  long long ans = 0;
  for (int i = 0; i < n - m + 1; ++i) {
    ans += cnt[i] == m;
  }
  printf("%lld\n", ans);
}
int main() {
  main2();
  return 0;
}

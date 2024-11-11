#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int N = 2001000;
struct FFT {
  complex<double> x1[N];
  void change(complex<double> y[], int len) {
    for (int i = 1, j = len / 2; i < len - 1; i++) {
      if (i < j) swap(y[i], y[j]);
      int k = len / 2;
      for (; k <= j; k >>= 1) j -= k;
      if (j < k) j += k;
    }
  }
  void fft(complex<double> y[], int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
      complex<double> wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
      for (int j = 0; j < len; j += h) {
        complex<double> w(1, 0);
        for (int k = j; k < j + h / 2; k++) {
          complex<double> u = y[k];
          complex<double> t = w * y[k + h / 2];
          y[k] = u + t;
          y[k + h / 2] = u - t;
          w = w * wn;
        }
      }
    }
  }
  int a[N];
  int num[N], s[N];
  void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      num[x] = s[x] = 1;
    }
    int len1 = m + 1, len = 1;
    for (; len < 2 * len1; len <<= 1)
      ;
    for (int i = 0; i < len1; i++) {
      x1[i] = complex<double>(num[i], 0);
    }
    for (int i = len1; i < len; i++) {
      x1[i] = complex<double>(0, 0);
    }
    fft(x1, len, 1);
    for (int i = 0; i < len; i++) {
      x1[i] = x1[i] * x1[i];
    }
    fft(x1, len, -1);
    for (int i = 0; i < len; i++) {
      x1[i] /= len;
      num[i] = (long long)(x1[i].real() + 0.5);
    }
    for (int i = 1; i <= m; i++) {
      if (num[i] && !s[i]) {
        puts("NO");
        return;
      }
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
      if (!num[i] && s[i]) {
        ans.push_back(i);
      }
    }
    puts("YES");
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
      printf("%d ", ans[i]);
    }
  }
} s;
int main() { s.solve(); }

#include <bits/stdc++.h>
const int MAX = 11;
const double PI = acos(-1);
const double eps = 1e-5;
void FFT(std::complex<double> *a, int length, int type) {
  for (int i = 1, j = 0; i < length - 1; ++i) {
    for (int s = length; j ^= s >>= 1, ~j & s;)
      ;
    if (i < j) {
      std::swap(a[i], a[j]);
    }
  }
  int len = -1;
  for (int x = length; x; ++len, x >>= 1)
    ;
  for (int i = 1; i <= len; ++i) {
    std::complex<double> unit(cos(PI / (1 << i - 1)),
                              type * sin(PI / (1 << i - 1)));
    for (int j = 0; j < length; j += 1 << i) {
      std::complex<double> w(1, 0);
      for (int k = j, szk = 1 << i - 1; k < j + szk; ++k) {
        std::complex<double> s = a[k], t = w * a[k + szk];
        a[k] = s + t, a[k + szk] = s - t;
        w *= unit;
      }
    }
  }
  if (type == 1) {
    return;
  }
  for (int i = 0; i < length; ++i) {
    a[i] /= (std::complex<double>)length;
  }
}
void mult(std::complex<double> (*compa)[1 << MAX], std::vector<int> lengtha,
          std::complex<double> (*compb)[1 << MAX], std::vector<int> lengthb) {
  std::vector<int> length = {1, 1};
  std::vector<int> n = {lengtha[1] + lengthb[1] - 1,
                        lengtha[0] + lengthb[0] - 1};
  for (int i = 0; i < 2; ++i) {
    for (; length[i] < n[i]; length[i] <<= 1)
      ;
  }
  for (int i = 0; i < lengtha[0]; ++i) {
    FFT(compa[i], length[0], 1);
  }
  for (int i = 0; i < lengthb[0]; ++i) {
    FFT(compb[i], length[0], 1);
  }
  for (int i = 0, sz = std::max(length[0], lengtha[0]); i < sz; ++i) {
    for (int j = 0; j < i; ++j) {
      std::swap(compa[i][j], compa[j][i]);
    }
  }
  for (int i = 0, sz = std::max(length[0], lengthb[0]); i < sz; ++i) {
    for (int j = 0; j < i; ++j) {
      std::swap(compb[i][j], compb[j][i]);
    }
  }
  for (int i = 0; i < length[0]; ++i) {
    FFT(compa[i], length[1], 1);
    FFT(compb[i], length[1], 1);
  }
  for (int i = 0; i < length[0]; ++i) {
    for (int j = 0; j < length[1]; ++j) {
      compa[i][j] *= compb[i][j];
    }
  }
  for (int i = 0; i < length[0]; ++i) {
    FFT(compa[i], length[1], -1);
  }
  for (int i = 0, sz = std::max(length[0], length[1]); i < sz; ++i) {
    for (int j = 0; j < i; ++j) {
      std::swap(compa[i][j], compa[j][i]);
    }
  }
  for (int i = 0; i < n[1]; ++i) {
    FFT(compa[i], length[0], -1);
  }
}
std::complex<double> a[1 << MAX][1 << MAX], b[1 << MAX][1 << MAX];
int n, m, r, c;
char s[1 << MAX][1 << MAX];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = std::complex<double>{sin(2 * PI * s[i][j] / 26),
                                     cos(2 * PI * s[i][j] / 26)};
    }
  }
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; ++i) {
    scanf("%s", s[i]);
  }
  int cnt = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      b[r - i - 1][c - j - 1] = s[i][j] == '?' ? ++cnt, 0
          : std::complex<double>{sin(2 * PI * s[i][j] / 26),
                                 -cos(2 * PI * s[i][j] / 26)};
    }
  }
  for (int i = 0; i < 1 << MAX - 1; ++i) {
    for (int j = 0; j < 1 << MAX - 1; ++j) {
      a[i][j] = a[i % n][j % m];
    }
  }
  mult(a, {1 << MAX - 1, 1 << MAX - 1}, b, {r, c});
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      putchar(std::abs(r * c - cnt - a[i + r - 1][j + c - 1].real()) < eps
                  ? '1'
                  : '0');
    }
    putchar('\n');
  }
  return 0;
}

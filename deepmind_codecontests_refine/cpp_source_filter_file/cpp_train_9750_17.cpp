#include <bits/stdc++.h>
using namespace std;
const double PI = atan(1.0) * 4;
const int MAXN = 500050;
complex<double> a[MAXN], b[MAXN];
int rev[MAXN];
bool dif[MAXN / 4][6][6];
int f[6];
string s, t;
int ls, lt, n, lim;
void fft(complex<double> c[], int n, int op) {
  for (int i = 0; i < n; ++i) {
    if (i < rev[i]) swap(c[i], c[rev[i]]);
  }
  for (int l = 2; l <= n; l <<= 1) {
    int m = l / 2;
    complex<double> wn =
        complex<double>(cos(2.0 * PI / l), op * sin(2.0 * PI / l));
    for (int i = 0; i < n; i += l) {
      complex<double> w = complex<double>(1, 0);
      for (int j = 0; j < m; ++j) {
        complex<double> u = w * c[i + j + m];
        c[i + j + m] = c[i + j] - u;
        c[i + j] += u;
        w *= wn;
      }
    }
  }
  if (op == -1) {
    for (int i = 0; i < n; ++i) {
      c[i].real(c[i].real() / n);
    }
  }
}
void solve(char c1, char c2) {
  for (int i = 0; i < n; ++i) {
    if (i < ls)
      a[i] = complex<double>(s[i] == c1 ? 1 : 0);
    else
      a[i] = complex<double>(0, 0);
    if (i < lt)
      b[i] = complex<double>(t[lt - i - 1] == c2 ? 1 : 0);
    else
      b[i] = complex<double>(0, 0);
  }
  fft(a, n, 1);
  fft(b, n, 1);
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  fft(a, n, -1);
  for (int i = 0; i < ls; ++i) {
    if (floor(a[i + lt - 1].real() + 0.5))
      dif[i][c1 - 'a'][c2 - 'a'] = true;
    else
      dif[i][c1 - 'a'][c2 - 'a'] = false;
  }
}
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int main() {
  cin >> s >> t;
  ls = s.length();
  lt = t.length();
  n = 1;
  lim = 0;
  while (n < ls + lt - 1) n <<= 1, lim++;
  for (int i = 0; i < n; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lim - 1));
  }
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (i != j) solve(i + 'a', j + 'a');
    }
  }
  for (int i = 0; i < ls - lt + 1; ++i) {
    int ans = 0;
    for (int j = 0; j < 6; ++j) f[j] = j;
    for (int j = 0; j < 6; ++j) {
      for (int k = 0; k < 6; ++k) {
        if (j == k) continue;
        if (dif[i][j][k]) {
          if (find(j) != find(k)) {
            ans++;
            f[j] = find(k);
          }
        }
      }
    }
    cout << ans << " \n"[i == ls - lt];
  }
}

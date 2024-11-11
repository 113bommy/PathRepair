#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
const int INF = 1e8;
const long double PI = acos(0.0) * 2.0;
inline void FFT(vector<complex<double> >& a, bool inverse) {
  int n = a.size();
  for (int i = 0, j = 0; i < n; i++) {
    if (j > i) swap(a[i], a[j]);
    int k = n;
    while (j & (k >>= 1)) j &= ~k;
    j |= k;
  }
  double pi = inverse ? -PI : PI;
  for (int step = 1; step < n; step <<= 1) {
    double alpha = pi / step;
    for (int k = 0; k < step; k++) {
      complex<double> omegak = exp(complex<double>(0, alpha * k));
      for (int Ek = k; Ek < n; Ek += step << 1) {
        int Ok = Ek + step;
        complex<double> t = omegak * a[Ok];
        a[Ok] = a[Ek] - t;
        a[Ek] += t;
      }
    }
  }
  if (inverse)
    for (int i = 0; i < n; i++) a[i] /= n;
}
inline vector<double> operator*(const vector<double>& v1,
                                const vector<double>& v2) {
  int s1 = v1.size(), s2 = v2.size(), S = 2;
  while (S < s1 + s2) S <<= 1;
  vector<complex<double> > a(S, 0), b(S, 0);
  for (int i = 0; i < s1; i++) a[i] = v1[i];
  FFT(a, false);
  for (int i = 0; i < s2; i++) b[i] = v2[i];
  FFT(b, false);
  for (int i = 0; i < S; i++) a[i] *= b[i];
  FFT(a, true);
  vector<double> res(s1 + s2 - 1);
  for (int i = 0; i < s1 + s2 - 1; i++) res[i] = a[i].real();
  return res;
}
char id[] = "AGCT";
char s1[maxn], s2[maxn];
int ans[maxn];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  scanf("%s%s", s1, s2);
  reverse(s2, s2 + m);
  memset(ans, 0, sizeof(ans));
  for (int i = (0); i < (4); ++i) {
    vector<double> a(n, 0), b(m, 0);
    int la = -1;
    for (int j = (0); j < (n); ++j) {
      if (s1[j] == id[i]) la = j;
      if (la >= j - k) a[j] = 1;
    }
    la = INF;
    for (int j = n - 1; j >= 0; --j) {
      if (s1[j] == id[i]) la = j;
      if (la <= j + k) a[j] = 1;
    }
    for (int j = (0); j < (m); ++j) {
      if (s2[j] == id[i]) b[j] = 1;
    }
    vector<double> res = a * b;
    int sz = min((int)res.size(), m + n);
    for (int j = (0); j < (n); ++j) ans[j] += (int)(res[j] + 0.5);
  }
  int cnt = 0;
  for (int j = (0); j < (n); ++j) {
    if (ans[j] == m) ++cnt;
  }
  printf("%d\n", cnt);
}

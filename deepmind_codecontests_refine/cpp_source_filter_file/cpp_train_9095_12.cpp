#include <bits/stdc++.h>
using namespace std;
int n, m, a[1001000];
bool wg[1001000], has[1001000];
int N;
int rev(int k, int siz) {
  int sol = 0, log = log2(siz) - 1;
  while (k) {
    if (k & 1) sol += 1 << log;
    k >>= 1;
    log--;
  }
  return sol;
}
void FFT(complex<double> *coef, complex<double> *pv, bool inverse) {
  int siz = 1 << ((int)ceil(log2(N + 1)));
  siz *= 2;
  for (int k = 0; k < siz; k++) pv[rev(k, siz)] = coef[k];
  for (int s = 1; s <= log2(siz); s++) {
    int m = 1 << s;
    double theta = (inverse ? -1 : 1) * 2 * acos(-1) / m;
    complex<double> unityRoot(cos(theta), sin(theta));
    for (int k = 0; k < siz; k += m) {
      complex<double> omega = 1;
      for (int j = 0; j < m / 2; j++) {
        complex<double> t = omega * pv[k + j + m / 2];
        complex<double> u = pv[k + j];
        pv[k + j] = u + t;
        pv[k + j + m / 2] = u - t;
        omega = omega * unityRoot;
      }
    }
  }
  if (inverse)
    for (int j = 0; j < siz; j++) pv[j] /= siz;
}
complex<double> p1[4200000], p2[4200000], p3[4200000];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    wg[a[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    bool v = true;
    for (int j = a[i]; j <= m; j += a[i])
      if (!wg[j]) v = false;
    if (!v) {
      printf("NO\n");
      return 0;
    }
    p1[a[i]] += 1;
  }
  N = 1000010;
  FFT(p1, p2, false);
  for (int i = 0; i < 4200000; i++) p1[i] = 0;
  for (int i = 0; i < n; i++) p1[a[i]] += 1;
  FFT(p1, p3, false);
  for (int i = 0; i < 4200000; i++) p2[i] *= p3[i];
  for (int i = 0; i < 4200000; i++) p1[i] = 0;
  FFT(p3, p1, true);
  vector<int> ans;
  for (int i = 1; i <= m; i++) {
    if (!wg[i] && p1[i].real() > 0.5) {
      printf("NO\n");
      return 0;
    }
    if (wg[i]) {
      if (p1[i].real() < 0.5) ans.push_back(i);
    }
  }
  printf("YES\n");
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}

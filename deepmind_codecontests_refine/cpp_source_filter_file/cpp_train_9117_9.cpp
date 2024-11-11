#include <bits/stdc++.h>
using namespace std;
int T;
int a[255];
long double fac[100000];
long double eps = 220;
long double calc(int p, int k) {
  if (k >= 100000) return -1e10;
  return k * log(p) - p - fac[k];
}
void work1() {
  double mx = -1e100;
  int u;
  for (int p = 10; p <= 1000; p++) {
    long double tmp = 0;
    for (int i = 1; i <= 250; i++) tmp += calc(a[i], p);
    if (tmp > mx) {
      mx = tmp;
      u = p;
    }
  }
  cout << min(max(u, 11), 950) << endl;
}
void work2() {
  int ret;
  if (a[250] & 1)
    ret = a[250] - 1 >> 1;
  else
    ret = a[250] >> 1;
  ret = 1.05 * ret + 0.5;
  cout << min(max(ret, 11), 950) << endl;
}
int main() {
  for (int i = 2; i < 100000; i++) fac[i] = fac[i - 1] + log(i);
  cin >> T;
  while (T--) {
    for (int i = 1; i <= 250; ++i) cin >> a[i];
    sort(a + 1, a + 250 + 1);
    int sta = (double)a[226] / 2;
    bool ok = 0;
    for (int i = 1; i <= 250; ++i) {
      int cnt = i;
      while (cnt <= 250 && a[cnt] - a[i] <= sta) cnt++;
      if ((cnt - i + 1) > eps) {
        ok = 1;
        break;
      }
    }
    if (a[250] > 2000) ok = 1;
    if (ok) {
      work1();
    } else {
      work2();
    }
  }
  return 0;
}

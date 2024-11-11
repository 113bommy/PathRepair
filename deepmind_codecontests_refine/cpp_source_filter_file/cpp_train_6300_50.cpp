#include <bits/stdc++.h>
using namespace std;
long double pne[111];
long double p[111];
long double pr[111];
long double sf[111];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    p[i] = x / 100.0;
    pne[i] = 1;
  }
  for (int i = 0; i + 1 < n; i++) {
    pne[i] = 1 - p[i];
  }
  long double ans = 0;
  for (int k = n; k <= 100031; k++) {
    for (int i = 0; i < n; i++) {
      pr[i] = 1 - pne[i];
      if (i) {
        pr[i] *= pr[i - 1];
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      sf[i] = 1 - pne[i];
      if (i + 1 < n) {
        sf[i] *= sf[i + 1];
      }
    }
    long double end_now = -1;
    int mx = -1;
    for (int i = 0; i < n; i++) {
      long double x = pne[i] * p[i];
      if (i > 0) {
        x *= pr[i - 1];
      }
      if (i + 1 < n) {
        x *= sf[i + 1];
      }
      if (x > end_now) {
        end_now = x;
        mx = i;
      }
    }
    pne[mx] *= 1 - p[mx];
    ans += k * end_now;
  }
  cout.precision(11);
  cout << fixed << ans;
  return 0;
}

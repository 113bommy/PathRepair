#include <bits/stdc++.h>
using namespace std;
int a[1010], n, mi, ma, lst, sol, solst, rat, ths;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  sol = (1 << 30);
  for (int i = 0; i <= 10001; ++i) {
    mi = ma = 0;
    for (int j = 2; j <= n; ++j) {
      ths = a[1] + (j - 1) * i;
      if (ths > a[j])
        ma = max(ma, ths - a[j]);
      else
        mi = max(mi, a[j] - ths);
    }
    if ((ma - mi > 10001) || (mi - ma > 10001)) continue;
    lst = a[1];
    if (ma > mi) {
      while (ma - mi >= 2) {
        ma--;
        mi++;
        lst--;
      }
    } else {
      while (mi - ma >= 2) {
        mi--;
        ma++;
        lst++;
      }
    }
    if (max(mi, ma) < sol) {
      sol = max(mi, ma);
      solst = lst;
      rat = i;
    }
  }
  cout << sol << "\n" << solst << " " << rat;
  return 0;
}

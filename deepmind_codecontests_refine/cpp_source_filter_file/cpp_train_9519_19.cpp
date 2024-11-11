#include <bits/stdc++.h>
using namespace std;
int n, m, c, d, k;
int main() {
  scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
  int s = n * m - k;
  int res;
  double fm, fr;
  fm = (double)n / (double)c;
  fr = (double)1 / (double)d;
  if (fm > fr) {
    res = s / n;
    s = s - (res * n);
    res = res * c;
    if (s != 0) {
      int ss = res + c;
      int sa = res + (s * d);
      res = min(ss, sa);
    }
  } else {
    res = s * d;
  }
  cout << res << endl;
  return 0;
}

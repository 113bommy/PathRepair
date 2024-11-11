#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, m, t;
int v[MAXN];
char s[MAXN];
int main() {
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ansa, ansb, ansc;
    int ans = 1e9;
    for (int i = 1; i <= int(2e4); i++) {
      int aa, bb, cc;
      int tmpans = abs(b - i);
      int tmp = 1e9;
      for (int j = 1; j * j <= i; j++) {
        if (i % j == 0) {
          if (tmp > abs(j - a)) {
            tmp = abs(j - a), aa = j;
          }
          if (tmp > abs(i / j - a)) {
            tmp = abs(i / j - a), aa = i / j;
          }
        }
      }
      if (a == i)
        tmp = 0, aa = i;
      else if (a > i)
        tmp = a - i, aa = i;
      tmpans += tmp;
      tmp = 1e9;
      int tmpp = c / i;
      if (abs(c - tmpp * i) > abs(c - (tmpp + 1) * i)) {
        tmp = abs(c - (tmpp + 1) * i), cc = (tmpp + 1) * i;
      } else {
        tmp = abs(c - tmpp * i), cc = (tmpp)*i;
      }
      if (c == i)
        tmp = 0, cc = i;
      else if (c < i)
        tmp = i - c, cc = i;
      tmpans += tmp;
      if (ans > tmpans) {
        ansa = aa, ansb = i, ansc = cc;
        ans = tmpans;
      }
    }
    cout << ans << endl << ansa << ' ' << ansb << ' ' << ansc << endl;
  }
}

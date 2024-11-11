#include <bits/stdc++.h>
using namespace std;
int q, w, e, W;
int a[500000], k, b, c, d, n, m, ip1, ip2, a1, b1, c1, d1, m1[500000],
    m2[500000], m3[500000], m4[500000];
string old[2000], nov[2000], s1, s2;
int main() {
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> s1 >> s2;
    int ok = 0;
    for (int j = 1; j <= k; j++)
      if (nov[j] == s1) {
        nov[j] = s2;
        ok = 1;
        break;
      }
    if (ok == 0) old[++k] = s1, nov[k] = s2;
  }
  cout << k << endl;
  for (int j = 1; j <= k; j++) cout << old[j] << ' ' << nov[j] << endl;
  return 0;
}

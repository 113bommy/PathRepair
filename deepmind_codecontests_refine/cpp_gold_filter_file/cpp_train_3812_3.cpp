#include <bits/stdc++.h>
using namespace std;
int n, a = 1, b = 2, m = 9999999;
int wsp[1001][5];
int od[1001][1001];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 5; j++) cin >> wsp[i][j];
  if (n == 1) {
    cout << 1 << endl << 1;
    return 0;
  }
  if (n == 2) goto out;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = 0; k < 5; k++)
        od[i][j] += (wsp[i][k] - wsp[j][k]) * (wsp[i][k] - wsp[j][k]);
      if (od[i][j] < m) {
        m = od[i][j];
        a = i;
        b = j;
      }
    }
  }
  for (auto l : {a, b}) {
    for (int i = 1; i <= n && l > 0; i++) {
      for (int j = i + 1; j <= n && l > 0; j++) {
        if (i != l && j != l) {
          int ab = 0, bc = 0, ac = 0;
          for (int k = 0; k < 5; k++) {
            bc += (wsp[i][k] - wsp[j][k]) * (wsp[i][k] - wsp[j][k]);
            ac += (wsp[l][k] - wsp[j][k]) * (wsp[l][k] - wsp[j][k]);
            ab += (wsp[l][k] - wsp[i][k]) * (wsp[l][k] - wsp[i][k]);
          }
          if (bc < ab + ac) {
            if (l == a)
              a = -1;
            else
              b = -1;
            l = -1;
          }
        }
      }
    }
  }
out:
  cout << (a >= 0) + (b >= 0) << endl;
  if (a >= 0) cout << a << endl;
  if (b >= 0) cout << b << endl;
  return 0;
}

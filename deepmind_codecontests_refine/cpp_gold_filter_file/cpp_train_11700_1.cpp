#include <bits/stdc++.h>
using namespace std;
char c[2000010], s[2000010];
int main() {
  ios_base::sync_with_stdio(0);
  int n, gd = 0, rd = 0, rp = 0, gp = 0, w = 0, sw = 0, cw = 0;
  cin >> n;
  n *= 2;
  cin >> s >> c;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' && c[i] == '1')
      w++;
    else {
      if (s[i] == '1') sw++;
      if (c[i] == '1') cw++;
    }
  }
  gd = w / 2;
  gp = w - gd;
  rp = gp;
  rd = gd;
  while (sw || cw) {
    if (rd < rp) {
      rd++;
      if (cw) {
        cw--;
        gd++;
      } else {
        if (sw) {
          sw--;
        }
      }
    } else {
      rp++;
      if (sw) {
        sw--;
        gp++;
      } else {
        if (cw) {
          cw--;
        }
      }
    }
  }
  if (gd > gp)
    cout << "Second";
  else if (gp > gd)
    cout << "First";
  else
    cout << "Draw";
  return 0;
}

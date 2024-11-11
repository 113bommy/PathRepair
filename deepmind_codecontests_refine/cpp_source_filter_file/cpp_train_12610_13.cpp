#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, i, j, k, l, n, m, x, y, t, p, aa, bb, cc, xx, yy,
      zz;
  string st;
  cin >> l;
  cin >> st;
  a = b = c = 0;
  x = l / 3;
  aa = bb = cc = 0;
  xx = yy = zz = 0;
  for (i = 0; i < l; i++) {
    if (st[i] == '0') {
      a++;
    }
    if (st[i] == '1') {
      b++;
    }
    if (st[i] == '2') {
      c++;
    }
  }
  for (i = 0; i < l; i++) {
    if (st[i] == '0') {
      aa++;
      if (aa > x) {
        if (b < x && yy < (x - b)) {
          yy++;
          st[i] = '1';
        } else if (c < x && zz < (x - c)) {
          zz++;
          st[i] = '2';
        }
      }
    } else if (st[i] == '1') {
      bb++;
      if (b > x) {
        if (a < x && xx < (x - a)) {
          xx++;
          b--;
          bb--;
          st[i] = '0';
        }
      }
      if (bb > x) {
        if (c < x && zz < (x - c)) {
          zz++;
          b--;
          st[i] = '2';
        }
      }
    } else if (st[i] == '2') {
      cc++;
      if (c > x) {
        if (a < x && xx < (x - a)) {
          xx++;
          c--;
          st[i] = '0';
        } else if (b < x && yy < (x - b)) {
          yy++;
          c--;
          st[i] = '2';
        }
      }
    }
  }
  cout << st << endl;
}

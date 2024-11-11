#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, j, n, m, po1, po2, w1, w2, z1, z2, lr, pr, li, pi, tw, ti;
  cin >> n;
  if ((n / 2) % 2 == 1) {
    cout << "! -1";
    return 0;
  }
  po1 = 1;
  po2 = n / 2 + 1;
  cout << "? " << po1 << endl;
  cin >> w1;
  cout << "? " << po2 << endl;
  cin >> w2;
  lr = w1 - w2;
  pr = -lr;
  li = 1;
  pi = n / 2 + 1;
  if (pr == 0) {
    cout << "! " << li;
    return 0;
  }
  for (i = 0; i < 29; i++) {
    ti = (pi + li) / 2;
    cout << "? " << ti << endl;
    cin >> z1;
    cout << "? " << ti + n / 2 << endl;
    cin >> z2;
    tw = z1 - z2;
    if (tw == 0) {
      cout << "! " << ti;
      return 0;
    }
    if (tw < 0) {
      if (lr < 0) {
        lr = tw;
        li = ti;
      } else {
        pr = tw;
        pi = ti;
      }
    } else {
      if (lr > 0) {
        lr = tw;
        li = ti;
      } else {
        pr = tw;
        pi = ti;
      }
    }
  }
}

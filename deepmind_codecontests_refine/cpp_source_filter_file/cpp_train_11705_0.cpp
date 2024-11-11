#include <bits/stdc++.h>
using namespace std;
int sq[1055];
map<int, int> mps;
int main() {
  int t, n, m, cas = 1, x, y, px, py, temp, xx, yy, f_i = 0, f_j, otivuj,
               s_i = 0, s_j;
  for (int i = 1; i < 1055; i++) {
    sq[i] = i * i;
    mps[sq[i]] = i;
  }
  cin >> x >> y;
  px = x * x;
  py = y * y;
  otivuj = px + py;
  if (x == y) {
    for (int i = 1; px > sq[i]; i++) {
      xx = px - sq[i];
      if (xx == sq[i]) continue;
      if (mps[xx]) {
        f_i = i;
        f_j = mps[xx];
        break;
      }
    }
    if (f_i != 0) {
      cout << "YES" << endl;
      cout << "0 0" << endl;
      cout << f_i << " " << f_j << endl;
      cout << -f_j << " " << f_i << endl;
    } else
      cout << "NO" << endl;
  } else {
    for (int i = 1; px > sq[i]; i++) {
      xx = px - sq[i];
      if (xx == sq[i]) continue;
      if (mps[xx]) {
        f_i = i;
        f_j = mps[xx];
        for (int j = 1; py > sq[j]; j++) {
          yy = py - sq[j];
          if (yy == sq[j]) continue;
          if (mps[yy]) {
            s_j = mps[yy];
            if (f_j == s_j) continue;
            if (((f_i + j) * (f_i + j) + (f_j - s_j) * (f_j - s_j)) != otivuj)
              continue;
            s_i = -j;
            break;
          }
        }
        if (s_i != 0) break;
      }
    }
    if (s_i != -1) {
      cout << "YES" << endl;
      cout << "0 0" << endl;
      cout << f_i << " " << f_j << endl;
      cout << s_i << " " << s_j << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int M = 300 + 10;
long long int Ax, Ay, Bx, By, Cx, Cy;
int main() {
  cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
  bool ok = false;
  for (int i = 0; i < 3; i++) {
    long long int squ = (Cx * Cx + Cy * Cy);
    long long int xbma = Bx - Ax;
    long long int ybma = By - Ay;
    long long int r1 = -xbma * Cy + ybma * Cx;
    long long int r2 = xbma * Cx + ybma * Cy;
    if (squ != 0) {
      if (r1 % squ == 0 && r2 % squ == 0) {
        ok = true;
        break;
      }
    } else {
      if (r1 == 0 && r2 == 0) {
        ok = true;
        break;
      }
    }
    long long int nx = Ay;
    long long int ny = -Ax;
    Ax = nx;
    Ay = ny;
  }
  string ans = ok ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}

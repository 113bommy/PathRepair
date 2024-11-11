#include <bits/stdc++.h>
using namespace std;
long long Det(long long a11, long long a12, long long a21, long long a22) {
  return a11 * a22 - a12 * a21;
}
bool HasSolution(long long Ax, long long Ay, long long Bx, long long By,
                 long long Cx, long long Cy) {
  long long d = Det(Cx, Cy, Cy, -Cx);
  long long d1 = Det(Bx - Ax, Cy, By - Ay, -Cx);
  long long d2 = Det(Cx, Bx - Ax, Cy, By - Ay);
  if (d != 0) return d1 % d == 0 && d2 % d == 0;
  return d1 == 0 && d2 == 0;
}
int main() {
  int Ax, Ay, Bx, By, Cx, Cy;
  cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
  bool t = HasSolution(Ax, Ay, Bx, By, Cx, Cy) ||
           HasSolution(Ay, -Ax, Bx, By, Cx, Cy) ||
           HasSolution(-Ax, -Ay, Bx, By, Cx, Cy) ||
           HasSolution(-Ay, Ax, Bx, By, Cx, Cy);
  cout << (t ? "YES" : "NO") << endl;
}

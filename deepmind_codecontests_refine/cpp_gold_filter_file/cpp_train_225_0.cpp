#include <bits/stdc++.h>
using namespace std;
int vert, oriz;
int xf, yf, xs, ys;
int dif_vert(int a, int b);
int dif_oriz(int a, int b);
int main() {
  int xf, xs, yf, ys;
  cin >> oriz >> vert >> xf >> yf >> xs >> ys;
  oriz *= 2;
  vert *= 2;
  int r = max(dif_vert(ys - xs, yf - xf), dif_oriz(xf + yf, xs + ys));
  cout << r;
  return 0;
}
int dif_oriz(int a, int b) {
  if (a <= 0 && b <= 0) a *= -1, b *= -1;
  if (a < b) swap(a, b);
  if (a == b) return 0;
  if (b == 0) return a / oriz + 1;
  if (b > 0) return a / oriz - (b - 1) / oriz;
  if (b < 0) return a / oriz + 1 - b / oriz;
}
int dif_vert(int a, int b) {
  if (a <= 0 && b <= 0) a *= -1, b *= -1;
  if (a < b) swap(a, b);
  if (a == b) return 0;
  if (b == 0) return a / vert + 1;
  if (b > 0) return a / vert - (b - 1) / vert;
  if (b < 0) return a / vert + 1 - b / vert;
}

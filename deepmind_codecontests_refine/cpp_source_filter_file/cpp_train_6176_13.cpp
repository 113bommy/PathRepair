#include <bits/stdc++.h>
using namespace std;
long n, m, k, l, r, g, h, dy[1000001], dx[1000001], xc, yc, x, y;
bool prime[1000001];
string s, t, q, w, e;
map<string, int> v;
map<int, int> p;
int gsd(int a, int b) {
  while (a * b > 0)
    if (a > b)
      a %= b;
    else
      b %= a;
  return a + b;
}
double len(int x1, int y1, int x2, int y2) {
  double le = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  return le;
}
int main() {
  cin >> n >> m >> xc >> yc >> k;
  for (int i = 1; i <= k; i++) {
    cin >> dx[i] >> dy[i];
    if (dx[i] < 0)
      x = 1, g = xc;
    else
      x = xc, g = n;
    if (dy[i] < 0)
      y = 1, h = yc;
    else
      y = yc, h = m;
    if (dx[i] != 0 && dy[i] != 0)
      l = min((g - x) / abs(dx[i]), (h - y) / abs(dy[i]));
    else if (dx[i] == 0)
      l = (h - y) / abs(dy[i]);
    else
      l = (g - x) / abs(dx[i]);
    r += l;
    xc += l * dx[i];
    yc += l * dy[i];
  }
  cout << r;
}

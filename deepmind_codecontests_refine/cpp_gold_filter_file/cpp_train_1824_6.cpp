#include <bits/stdc++.h>
using namespace std;
long long int modulo = 1e9 + 7;
long long int div2 = 500000004;
struct point {
  long long int x, y;
  point() { x = y = 0; }
  point(long long int inx, long long int iny) {
    x = iny;
    y = iny;
  }
};
point modularizar(point p) {
  p.x %= modulo;
  p.y %= modulo;
  return p;
}
point operator*(long long int a, point p) {
  p.x *= a;
  p.y *= a;
  return p;
}
point operator+(point p1, point p2) {
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}
point operator-(point p1, point p2) {
  p1.x -= p2.x;
  p1.y -= p2.y;
  return p1;
}
long long int prodvec(point p1, point p2) { return p1.x * p2.y - p1.y * p2.x; }
const int limite = 2000000;
int n;
void escribe(long long int v[limite]) {
  for (int i = 1; i <= 3 * n; i++) cout << v[i] << ",";
  cout << endl;
}
void anular(long long int v[limite]) {
  for (int i = 1; i <= 3 * n; i++) v[i] = 0;
}
point p[limite];
point sumap[limite];
long long int pv[limite];
long long int area[limite];
long long int acum[limite];
long long int addinc[limite];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  reverse(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) p[i + 2 * n] = p[i + n] = p[i];
  for (int i = 1; i <= 3 * n; i++) sumap[i] = sumap[i - 1] + p[i];
  for (int i = 2; i <= 3 * n; i++) {
    pv[i] = prodvec(p[i - 1], p[i]);
    area[i] = area[i - 1] + pv[i];
  }
  long long int areatotal = area[n + 1];
  int i2 = 1;
  long long int sol = 0;
  for (int i1 = 1; i1 <= n; i1++) {
    i2 = max(i1, i2);
    while ((area[i2 + 1] - area[i1] + prodvec(p[i2 + 1], p[i1])) <=
           areatotal / 2)
      i2++;
    acum[i1] += (n + i1 - 2 - i2) - (i2 - i1 - 1);
    addinc[i1 + 1] += 2;
    addinc[i2] -= 4;
    addinc[i1 + n - 2] += 2;
    acum[i1 + n] -= (i2 - i1 - 1) - (n + i1 - 2 - i2);
    sol = (sol +
           prodvec(p[i1], modularizar(2 * (sumap[i2] - sumap[i1 + 1]) -
                                      2 * (sumap[i1 + n - 2] - sumap[i2])))) %
          modulo;
  }
  long long int acu = 0, inc = 0;
  for (int i = 1; i < 3 * n; i++) {
    acu = (acu + acum[i] + inc) % modulo;
    sol = (sol + pv[i + 1] % modulo * acu) % modulo;
    inc += addinc[i];
  }
  sol = (sol * div2) % modulo;
  cout << (sol % modulo + modulo) % modulo << endl;
}

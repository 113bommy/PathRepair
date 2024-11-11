#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a, b, x1, x2, y11, y2;
int NOD(int a, int b) {
  if (a == 0)
    return b;
  else
    return NOD(b % a, a);
}
void change(int *a, int *b) {
  int nod;
  nod = NOD(*a, *b);
  *a = *a / nod;
  *b = *b / nod;
  int k;
  k = n / (*a);
  if (m / (*b) < k) k = m / (*b);
  *a = *a * k;
  *b = *b * k;
}
int main() {
  cin >> n >> m >> x >> y >> a >> b;
  change(&a, &b);
  x2 = x + a / 2;
  y2 = y + b / 2;
  x1 = x2 - a;
  y11 = y2 - b;
  if (x2 > n) {
    x2 = n;
    x1 = x2 - a;
  }
  if (y2 > m) {
    y2 = m;
    y11 = y2 - b;
  }
  if (x1 < 0) {
    x1 = 0;
    x2 = a;
  }
  if (y11 < 0) {
    y11 = 0;
    y2 = b;
  }
  cout << x1 << ' ' << y11 << ' ' << x2 << ' ' << y2;
}

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int ask(int x, int y) {
  cout << "? " << x << " " << y << endl;
  cout.flush();
  cin >> x;
  return x;
}
int main() {
  int v1 = ask(1, 1), v2 = ask(1, inf), v3 = ask(inf, 1), v4 = ask(inf, inf);
  int d1 = (inf - v3 + v1) / 2, d2 = (inf - v2 + v1) / 2,
      d3 = (inf - v4 + v2) / 2, d4 = (inf - v4 + v3) / 2;
  int x, y, p, q;
  x = ask(1, d2) + 1;
  y = ask(d1, 1) + 1;
  p = inf - ask(inf, d4);
  q = inf - ask(d3, inf);
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
  cout.flush();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve(int h, int x, int y, int a, int &p, int &q, int m) {
  p = q = -1;
  if (h == a) p = 0;
  for (int i = 1; i <= 500000; i++) {
    h = (1LL * h * x + y) % m;
    if (h == a) {
      if (p == -1)
        p = i;
      else {
        q = i - p;
        break;
      }
    }
  }
}
int main() {
  int m;
  cin >> m;
  int h1, a1;
  cin >> h1 >> a1;
  int x1, y1;
  cin >> x1 >> y1;
  int h2, a2;
  cin >> h2 >> a2;
  int x2, y2;
  cin >> x2 >> y2;
  int p1, q1, p2, q2;
  solve(h1, x1, y1, a1, p1, q1, m);
  solve(h2, x2, y2, a2, p2, q2, m);
  if (p1 == -1 || p2 == -1) {
    cout << -1 << endl;
    return 0;
  }
  if (q1 == -1 && q2 == -1) {
    if (p1 == p2)
      cout << p1 << endl;
    else
      cout << -1 << endl;
  } else if (q1 == -1) {
    if (p1 < p2) {
      cout << -1 << endl;
    } else if ((p1 - p2) % q2)
      cout << -1 << endl;
    else
      cout << p1 << endl;
  } else if (q2 == -1) {
    if (p2 < p1)
      cout << -1 << endl;
    else if ((p2 - p1) % q1)
      cout << -1 << endl;
    else
      cout << p2 << endl;
  } else {
    for (long long i = 0; i <= 10000000; i++) {
      long long x = i * q2 + p2;
      if (x < p1) continue;
      if ((x - p1) % q1) continue;
      cout << x << endl;
      return 0;
    }
    cout << -1 << endl;
  }
  return 0;
}

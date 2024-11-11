#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)(1e5) + 100;
const int INF = (1 << 30);
const double PI = acos(-1.0);
const double EPS = (1e-6);
int main() {
  int x, y;
  cin >> x >> y;
  int k = abs(x) + abs(y);
  int xa = k;
  int ya = 0;
  int xb = 0;
  int yb = k;
  if (x < 0) xa = -xa;
  if (y < 0) ya = -ya;
  pair<int, int> p1 = make_pair(xa, ya), p2 = make_pair(xb, yb);
  if (p1 > p2) swap(p1, p2);
  cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second
       << endl;
  return 0;
}

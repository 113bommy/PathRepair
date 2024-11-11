#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  char t[10];
  int a, b, p, d;
  int ans[8];
  fill(ans, ans + 8, -2.01e9);
  while (n--) {
    scanf("%s%d%d", t, &a, &b);
    p = -1;
    if (a == x && b > y) {
      p = 0;
      d = (b - y) * (t[0] == 'B' ? -1 : 1);
    }
    if (a == x && b < y) {
      p = 1;
      d = (y - b) * (t[0] == 'B' ? -1 : 1);
    }
    if (b == y && a > x) {
      p = 2;
      d = (a - x) * (t[0] == 'B' ? -1 : 1);
    }
    if (b == y && a < x) {
      p = 3;
      d = (x - a) * (t[0] == 'B' ? -1 : 1);
    }
    if (a - x == b - y && b > y) {
      p = 5;
      d = (b - y) * (t[0] == 'R' ? -1 : 1);
    }
    if (a - x == b - y && b < y) {
      p = 6;
      d = (y - b) * (t[0] == 'R' ? -1 : 1);
    }
    if (a - x == -b + y && b > y) {
      p = 7;
      d = (b - y) * (t[0] == 'R' ? -1 : 1);
    }
    if (a - x == -b + y && b < y) {
      p = 4;
      d = (y - b) * (t[0] == 'R' ? -1 : 1);
    }
    if (p >= 0 && abs(d) < abs(ans[p])) ans[p] = d;
  }
  for (int i = 0; i < 8; i++)
    if (ans[i] > 0) {
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
  return 0;
}

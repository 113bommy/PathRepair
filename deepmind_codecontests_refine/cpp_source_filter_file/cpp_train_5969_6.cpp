#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t-- > 0) {
    int n, m, x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &n, &m, &x1, &y1, &x2, &y2);
    if (x2 < x1) swap(x1, x2);
    swap(y1, y2);
    if (y1 < y2) swap(y1, y2);
    long long dx = x2 - x1, dy = y1 - y2;
    long long k = 2 * dx * dy;
    long long a = dx - (n - dx), b = dy - (m - dy);
    if (a > 0 && b > 0) k -= a * b;
    cout << k << endl;
  }
  return 0;
}

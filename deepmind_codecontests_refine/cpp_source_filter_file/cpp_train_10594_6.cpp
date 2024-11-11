#include <bits/stdc++.h>
using namespace std;
struct S {
  double x, y;
} a[4], b[4], c[2], d[2];
int main() {
  for (int i = 0; i < 3; i++) cin >> a[i].x >> a[i].y;
  for (int j = 0; j < 3; j++) cin >> b[j].x >> b[j].y;
  c[0].x = c[0].y = d[0].x = d[0].y = 1007;
  c[1].x = c[1].y = d[1].y = d[1].x = -1007;
  for (int i = 0; i < 3; i++) {
    c[0].x = min(c[0].x, a[i].x);
    c[0].y = min(c[0].y, a[i].y);
    c[1].x = max(c[1].x, a[i].x);
    c[1].y = max(c[1].y, a[i].y);
    d[0].x = min(d[0].x, b[i].x);
    d[0].y = min(d[0].y, b[i].y);
    d[1].x = max(d[1].x, b[i].x);
    d[1].y = max(d[1].y, b[i].y);
  }
  double x = (d[0].x + d[1].x) / 2, y = (d[0].y + d[1].y) / 2, n, m, sum;
  for (int i = c[0].x; i <= c[1].x; i++)
    for (int j = c[0].y; j <= c[1].y; j++) {
      n = (d[1].y - y) / (x - d[1].x);
      m = d[1].y - n * x;
      sum = n * i + m;
      if (sum < j) continue;
      n = (d[1].y - y) / (x - d[0].x);
      m = y - n * d[0].x;
      sum = n * i + m;
      if (sum < j) continue;
      n = (d[0].y - y) / (x - d[0].x);
      m = y - d[0].x * n;
      sum = n * i + m;
      if (sum > j) continue;
      n = (d[0].y - y) / (x - d[1].x);
      m = y - n * d[1].x;
      sum = n * i + m;
      if (sum > j) continue;
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
  return 0;
}

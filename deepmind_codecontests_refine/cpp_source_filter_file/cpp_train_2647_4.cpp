#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, x1[100], y1[100];
  cin >> n;
  for (int i = 0; i < 100; i++) x1[i] = y1[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    x1[x]++;
    y1[y]++;
  }
  int hor = 0, ver = 0;
  for (int i = 0; i < 100; i++)
    if (x1[i]) hor++;
  for (int i = 0; i < 100; i++)
    if (y1[i]) ver++;
  int m = (hor > ver) ? hor : ver;
  cout << m;
}

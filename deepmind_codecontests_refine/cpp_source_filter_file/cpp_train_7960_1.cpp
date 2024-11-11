#include <bits/stdc++.h>
using namespace std;
int bin(int a[], int n, int x) {
  int l = 1, r = n;
  int m = 0;
  while (l <= r) {
    m = (l + r) / 2;
    if (a[m] > x)
      r = m - 1;
    else if (a[m] < x)
      l = m + 1;
    else
      return m;
  }
  return l;
}
int a[1005], bo[1004], gl[1005];
int main() {
  int n, m, i = 0, j, x, b, g, k;
  cin >> n;
  cin >> m;
  while (m) {
    x = m % 10;
    m /= 10;
    if (x == 1 || x == 0) {
      continue;
    }
    if (x == 6) {
      a[++i] = 5;
      a[++i] = 3;
    } else if (x == 4) {
      a[++i] = 3;
      a[++i] = 2;
      a[++i] = 2;
    } else if (x == 8) {
      a[++i] = 7;
      a[++i] = 2;
      a[++i] = 2;
      a[++i] = 2;
    } else if (x == 9) {
      a[++i] = 7;
      a[++i] = 3;
      a[++i] = 3;
      a[++i] = 2;
    } else
      a[++i] = x;
  }
  sort(a + 1, a + i + 1);
  while (i) {
    cout << a[i--];
  }
}

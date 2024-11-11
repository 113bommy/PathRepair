#include <bits/stdc++.h>
using namespace std;
void quicksort(int *a, int n);
int main() {
  srand(time(0));
  double x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double abx = x2 - x1;
  double aby = y2 - y1;
  double bcx = x3 - x2;
  double bcy = y3 - y2;
  if ((-abx) * bcy - (-aby) * bcx > 0)
    cout << "RIGHT";
  else if ((-abx) * bcy - (-aby) * bcx < 0)
    cout << "LEFT";
  else
    cout << "RIGHT";
  return 0;
}
void quicksort(int *a, int n) {
  if (n <= 1) return;
  int m = n / 2;
  int l = 0, r = n - 1;
  int s;
  while (l != r) {
    while (a[l] < a[m]) l++;
    while (a[r] > a[m]) r--;
    if ((r != m) && (l != m)) {
      s = a[l];
      a[l] = a[r];
      a[r] = s;
      l++;
      r--;
      continue;
    }
    if ((r == m) && (l != m)) {
      s = a[l];
      a[l] = a[r];
      a[r] = s;
      m = l;
      r--;
      continue;
    }
    if ((r != m) && (l == m)) {
      s = a[l];
      a[l] = a[r];
      a[r] = s;
      m = r;
      l++;
      continue;
    }
  }
  quicksort(a, m);
  quicksort(a + m + 1, n - m - 1);
}

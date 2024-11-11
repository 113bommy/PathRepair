#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[5000];
void qsort(int l, int r) {
  long long x = a[(l + r) / 2];
  int i = l;
  int j = r;
  do {
    while (a[i] < x) ++i;
    while (a[j] > x) --j;
    if (i <= j) {
      swap(a[i], a[j]);
      ++i;
      --j;
    }
  } while (i <= j);
  if (l < j) qsort(l, j);
  if (i < r) qsort(i, r);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> a[i];
  qsort(0, m - 1);
  bool res = true;
  if (a[0] == 1 || a[m - 1] == n) res = false;
  if (res && m >= 3)
    for (int i = 2; i < m; ++i) {
      if (a[i - 2] + 2 == a[i]) {
        res = false;
        break;
      }
    }
  if (res)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}

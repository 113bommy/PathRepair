#include <bits/stdc++.h>
using namespace std;
int a[10005], b[10005];
int main() {
  char s[101];
  int n, m, i, j, k, l, count = 0, flag = 0, d, e, f;
  cin >> n >> m >> l >> i >> j >> k;
  d = (n - i) / 2;
  e = (m - j) / 2;
  f = (l - k) / 2;
  if (d < 0) d = 0;
  if (e < 0) e = 0;
  if (f < 0) f = 0;
  count = d + e + f;
  if (n < i) {
    count -= (i - n);
  }
  if (m < j) count -= (j - m);
  if (l < k) count -= (k - l);
  if (count < 0)
    cout << "No";
  else
    cout << "Yes";
}

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int a[222], n, _0 = 0;
int main() {
  int i, j, k = 0;
  cin >> n;
  for (i = 1; i <= n + n - 1; ++i) {
    cin >> a[i];
    if (a[i] < 0) ++k, a[i] = -a[i];
    if (a[i] == 0) _0++;
  }
  int kk = inf;
  if (k >= n) k -= n;
  if (k + _0 >= n) kk = 0;
  kk = min(kk, k % 2);
  kk = min(kk, (n - k) % 2);
  sort(a + 1, a + n + n);
  int sum = 0;
  j = 1;
  for (i = 1; i <= n + n - 1; ++i) {
    if (a[i] != 0 && j <= kk) {
      sum -= a[i];
      ++j;
    } else
      sum += a[i];
  }
  cout << sum;
  return 0;
}

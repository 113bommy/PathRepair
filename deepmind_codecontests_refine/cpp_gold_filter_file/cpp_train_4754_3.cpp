#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k, ans, x, a[20], b[20], pos, mx;
int main() {
  for (i = 1; i <= 14; ++i) cin >> a[i];
  for (i = 1; i <= 14; ++i) {
    for (j = 1; j <= 14; ++j) b[j] = a[j];
    mx = 0;
    b[i] = 0;
    k = a[i] / 14;
    x = a[i] % 14;
    for (j = 1; j <= 14; ++j) b[j] += k;
    pos = i + 1;
    while (x > 0) {
      --x;
      if (pos == 15) pos = 1;
      b[pos]++;
      pos++;
    }
    for (j = 1; j <= 14; ++j)
      if (b[j] % 2 == 0) mx += b[j];
    ans = max(ans, mx);
  }
  cout << ans;
}

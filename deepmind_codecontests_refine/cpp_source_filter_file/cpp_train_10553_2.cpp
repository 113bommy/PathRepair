#include <bits/stdc++.h>
const int MAX_N = 1e6;
using namespace std;
long long ans = 0;
int f[MAX_N][8];
char a[MAX_N];
char b[MAX_N];
int l, r, x, y, n, m;
int main() {
  scanf("%s", a);
  scanf("%s", b);
  for (n = 0; a[n]; n++) a[n] %= 3;
  for (m = 0; b[m]; m++) b[m] %= 3;
  for (int i = 1; i < n; i++) {
    memcpy(f[i], f[i - 1], 32);
    if (a[i] != a[i - 1]) {
      ++f[i][(a[i] < a[i - 1]) * 4 + a[i] + a[i - 1]];
    }
  }
  memcpy(f[n], f[n - 1], 32);
  for (int i = 0; i < m; i++) {
    if (i && b[i] != b[i - 1]) {
      int x = (b[i] > b[i - 1]) * 4 + b[i] + b[i - 1];
      ans -= f[r][x] - f[l][x];
    }
    while (r < n && a[r] != b[i]) ++r;
    ans += r - l + 1 - (r == n);
    if (r < n) ++r;
    if (l < r && a[l] == b[i]) ++l;
  }
  cout << ans << endl;
  return 0;
}

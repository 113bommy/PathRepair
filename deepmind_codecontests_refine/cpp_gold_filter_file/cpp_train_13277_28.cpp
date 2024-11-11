#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int n, a[maxN], c[maxN], d[maxN], tot;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], c[i] = a[i];
  sort(c, c + n);
  tot = unique(c, c + n) - c;
  for (int i = 0; i < n; i++) d[lower_bound(c, c + tot, a[i]) - c]++;
  int ans = 0;
  for (int i = 0; i < tot; i++) {
    ans += d[i];
    if (ans > c[i]) ans = c[i];
  }
  cout << ans + 1;
  return 0;
}

#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 998244353;
using namespace std;
int a[110];
void solve() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 1, x; i <= n; ++i) scanf("%d", &x), a[x] = 1;
  int ans = 101;
  for (int i = 1; i <= 100 && x; ++i)
    if (a[i] == 0) a[i] = 1, x--;
  for (int i = 1; i <= 100; ++i)
    if (a[i] == 0) {
      ans = i - 1;
      break;
    }
  printf("%d\n", ans);
  memset(a, 0, sizeof(a));
}
int main() {
  int _ = 1;
  scanf("%d", &_);
  while (_--) solve();
  return 0;
}

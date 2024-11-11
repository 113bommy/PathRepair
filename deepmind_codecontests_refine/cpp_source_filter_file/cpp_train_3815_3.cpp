#include <bits/stdc++.h>
using namespace std;
long long a[100010], p[100010];
int f(int x) {
  if (p[x] == x) return x;
  p[x] = f(p[x]);
  return p[x];
}
int main() {
  long long n, m, i, x, y, ans = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) p[i] = i;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    f(x);
    f(y);
    if (p[x] == p[y])
      ans *= 2, ans++, ans %= 1000000007;
    else
      p[p[x]] = y;
    cout << ans << '\n';
  }
}

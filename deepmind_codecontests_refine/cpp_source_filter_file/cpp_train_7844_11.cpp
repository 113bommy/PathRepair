#include <bits/stdc++.h>
using namespace std;
const int MAX = 109;
int n, a[MAX], ans;
void dfs(int v) {
  if (2 * v + 1 <= n) dfs(2 * v), dfs(2 * v + 1);
  ans += max(a[2 * v], a[2 * v + 1]),
      a[v] = max(0, a[v] - max(a[2 * v], a[2 * v + 1]));
}
int main() {
  cin >> n;
  if (n == 1) return cout << -1, 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if ((i / 2) * 2 + 1 > n) return cout << -1, 0;
  }
  dfs(1);
  cout << ans + a[1];
}

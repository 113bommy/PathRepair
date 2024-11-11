#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  int p[2 * n + 1];
  memset(p, 0, sizeof p);
  int s = find(a, a + n, m) - a, ba = n;
  for (int i = s; i < n; i++) {
    if (a[i] > m)
      ba++;
    else if (a[i] < m)
      ba--;
    p[ba]++;
  }
  ba = 0;
  int ans = 0;
  for (int i = s; i >= 0; i--) {
    if (a[i] > m)
      ba++;
    else if (a[i] < m)
      ba--;
    ans += p[n - ba] + p[n - ba + 1];
  }
  cout << ans;
  return 0;
}

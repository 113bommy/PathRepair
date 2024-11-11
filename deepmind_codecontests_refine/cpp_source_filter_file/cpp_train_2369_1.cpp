#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int n, m;
int a[1 << 23];
bool have[1 << 23], vis[1 << 23];
void dfs(int mask) {
  if (vis[mask]) return;
  vis[mask] = 1;
  for (int i = 0; i < n; i++) {
    if ((mask >> i & 1)) {
      dfs(mask - (1 << i));
    }
  }
  if (have[mask]) dfs((1 << n) - 1 - mask);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    have[a[i]] = 1;
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    if (have[mask] && !vis[mask]) {
      ans++;
      vis[mask] = 1;
      dfs((1 << n) - 1 - mask);
    }
  }
  cout << ans << endl;
  return 0;
}

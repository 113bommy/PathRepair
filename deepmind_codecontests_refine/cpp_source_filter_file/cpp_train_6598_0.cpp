#include <bits/stdc++.h>
using namespace std;
int p[1000010];
int n, m;
long long ans;
void dfs(int n) {
  if (n <= 0) return;
  int i;
  for (i = 20; i >= 0; i--)
    if (n >> i & 1) break;
  m = 1 << i;
  for (int j = n - m; j >= 0; j--) {
    p[m + j] = m - 1 - j;
    p[m - 1 - j] = m + j;
    ans += 2 * ((1 << i + 1) - 1);
  }
  dfs(m - 2 - (n - m));
}
int main() {
  cin >> n;
  dfs(n);
  cout << ans << endl;
  for (int i = 0; i <= n; i++) cout << p[i];
  cout << endl;
  return 0;
}

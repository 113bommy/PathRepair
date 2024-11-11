#include <bits/stdc++.h>
using namespace std;
const int Maxn = 30 + 5;
long long n, r, u, p[Maxn], a[Maxn], b[Maxn], k[Maxn], arr[Maxn][Maxn],
    ans = LLONG_MIN, sum;
void dfs(int v, int h) {
  if (h == u) return;
  sum = 0;
  if (v % 2 == 0) {
    for (int i = 0; i < n; i++) {
      arr[h + 1][i] = arr[h][i] ^ b[i];
      sum += arr[h + 1][i] * k[i];
    }
    if ((h + 1) % 2 == u % 2) ans = max(sum, ans);
    dfs(v * 2 + 1, h + 1);
  } else {
    for (int i = 0; i < n; i++) {
      arr[h + 1][i] = arr[h][p[i]] + r;
      sum += arr[h + 1][i] * k[i];
    }
    if ((h + 1) % 2 == u % 2) ans = max(sum, ans);
    dfs(v * 2 + 1, h + 1);
    dfs(v * 2, h + 1);
  }
  return;
}
int main() {
  cin >> n >> u >> r;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) arr[0][i] = a[i];
  if (u % 2 == 0) {
    for (int i = 0; i < n; i++) sum += a[i] * k[i];
    ans = max(ans, sum);
  }
  dfs(0, 0);
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}

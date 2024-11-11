#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[50 + 1];
bool vis[50][50];
bool possible(long long need, int idx, int used) {
  if (idx == n) {
    if (used == k) return 1;
    return 0;
  }
  if (used >= k) return 0;
  if (idx == 0 && used == 0)
    for (int i = 0; i < (n); i++)
      for (int j = 0; j < (k); j++) vis[i][j] = 0;
  if (vis[idx][used]) return 0;
  vis[idx][used] = 1;
  for (int i = (idx + 1); i < (n + 1); i++)
    if (((a[i] - a[idx]) & need) == need && possible(need, i, used + 1))
      return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < (n); i++) cin >> a[i + 1];
  for (int i = (1); i < (n + 1); i++) a[i] += a[i - 1];
  long long res = 0;
  for (int i = (63) - 1; i >= 0; i--)
    if (possible(res | (1LL << i), 0, 0)) res |= (1LL << i);
  cout << res << endl;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000 + 2;
int a[MAX_N];
int n, k;
int mark[MAX_N];
int dfs(int i) {
  mark[i] = 1;
  if ((long long)a[i] * k > 1000000000) return 1;
  int j = lower_bound(a, a + n, a[i] * k) - a;
  if (j < n && a[j] == a[i] * k)
    return 1 + dfs(j);
  else
    return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (!mark[i]) ans += (dfs(i) + 1) / 2;
  cout << ans << endl;
  return 0;
}

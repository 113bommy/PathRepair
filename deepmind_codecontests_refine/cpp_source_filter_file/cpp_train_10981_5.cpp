#include <bits/stdc++.h>
using namespace std;
int a[20];
int n, l, r, x;
int cnt = 0;
void dfs(int index, int maxn, int minn, int sum) {
  if (index == n) {
    if (sum >= l && sum <= r && maxn - minn >= x) cnt++;
    return;
  }
  if (sum > r) return;
  dfs(index + 1, maxn, minn, sum);
  dfs(index + 1, max(maxn, a[index]), min(minn, a[index]), sum + a[index]);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> l >> r >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(1, 0, INT_MAX, 0);
  cout << cnt;
  return 0;
}

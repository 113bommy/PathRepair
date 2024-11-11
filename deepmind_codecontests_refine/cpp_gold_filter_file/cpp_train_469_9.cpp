#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 18;
pair<int, int> tree[maxn * 2];
void build(const vector<int> &a, int n) {
  for (int i = 0; i < n; i++) tree[maxn + i] = {a[i], i};
  for (int i = maxn - 1; i > 0; i--)
    tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}
int get(int l, int r) {
  pair<int, int> ans = make_pair(-1, 1);
  for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, tree[l++]);
    if (r & 1) ans = max(ans, tree[--r]);
  }
  return ans.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  a[n - 1] = n - 1;
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
    a[i]--;
  }
  build(a, n);
  vector<long long> dp(n);
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    int m = get(i + 1, a[i]);
    dp[i] = dp[m] - i + n - 1 + m - a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i];
  }
  cout << ans;
}

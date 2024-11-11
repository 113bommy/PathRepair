#include <bits/stdc++.h>
using namespace std;
const int maxn = 200500;
int a[maxn], b[maxn], mp[maxn], ordn[maxn];
int n, m;
int ck(int idx, int ord) {
  if (idx < 1) return 0;
  if (idx > n) return 0;
  if (ordn[a[idx]] > ord) return 0;
  return 1;
}
void solve() {
  cin >> n >> m;
  for (int i = (1), iend = (n); i <= iend; i++) cin >> a[i], mp[a[i]] = i;
  for (int i = (1), iend = (m); i <= iend; i++) cin >> b[i], ordn[b[i]] = i;
  int ans = 1;
  for (int i = (1), iend = (m); i <= iend; i++) {
    int cnt = ck(mp[b[i]] - 1, i) + ck(mp[b[i]] + 1, i);
    ans = 1ll * ans * cnt % 998244353;
  }
  cout << ans;
  for (int i = (1), iend = (n); i <= iend; i++)
    ordn[i] = mp[i] = a[i] = b[i] = 0;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}

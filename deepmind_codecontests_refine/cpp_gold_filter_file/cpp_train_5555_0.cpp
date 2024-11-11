#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, SQ = 500;
int n, q, l, r, ans, a[MAXN + 50], dp[MAXN + 50][SQ];
map<int, int> cnt;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= MAXN) continue;
    cnt[a[i]]++;
    if (cnt[a[i]] == a[i]) v.push_back(a[i]);
  }
  for (int i = 0; i < v.size(); i++) {
    int u = v[i], tmp = 0;
    for (int j = 1; j <= n; j++) tmp += (a[j - 1] == u), dp[j][i] = tmp;
  }
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    ans = 0;
    for (int j = 0; j < v.size(); j++) ans += (v[j] == dp[r][j] - dp[l - 1][j]);
    cout << ans << '\n';
  }
}

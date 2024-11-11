#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, M = 2 * N, mod = 998244353;
int first[N];
string s[N];
int ans[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> first[i];
  for (int i = 1; i <= n; i++) cin >> s[i], s[i] = " " + s[i];
  long long res = 0, tmp;
  for (int k = 0; k < (1 << n); k++) {
    tmp = 0;
    for (int i = 0; i < n; i++) {
      int r = 1;
      if (k >> i & 1) r = -1;
      tmp += r * first[i + 1];
    }
    vector<pair<int, int> > num;
    for (int i = 1; i <= m; i++) {
      int tmp = 0;
      for (int j = 0; j < n; j++) {
        int r = -1;
        if (k >> j & 1) r = 1;
        tmp += (s[j + 1][i] - '0') * r;
      }
      num.push_back({tmp, i});
    }
    sort((num).begin(), (num).end());
    for (int i = 1; i <= m; i++) tmp += num[i - 1].first * i;
    if (res < tmp) {
      res = tmp;
      for (int i = 0; i < m; i++) {
        auto &[val, id] = num[i];
        ans[id] = i + 1;
      }
    }
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cout.precision(2), cout.setf(ios::fixed);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

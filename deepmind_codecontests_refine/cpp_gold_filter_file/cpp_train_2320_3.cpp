#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const long long mod = 1e9 + 7;
int a[10];
vector<pair<int, int> > v;
int cnt[maxn], cnt2 = 0;
void add(int x) {
  cnt[x]++;
  if (cnt[x] == 1) cnt2++;
}
void sub(int x) {
  cnt[x]--;
  if (cnt[x] == 0) cnt2--;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 6; i++) cin >> a[i];
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= 6; j++) v.push_back({x - a[j], i});
  }
  sort((v).begin(), (v).end());
  int ans = inf;
  int r = -1;
  for (int i = 0; i < 6 * n; i++) {
    if (i > 0) sub(v[i - 1].second);
    while (r < 6 * n - 1 && cnt2 != n) add(v[++r].second);
    if (r != 6 * n - 1) ans = min(ans, v[r].first - v[i].first);
  }
  cout << ans << '\n';
}

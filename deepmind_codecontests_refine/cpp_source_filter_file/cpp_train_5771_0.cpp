#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, MOD = 1e9 + 9;
const long long inf = 1e16 + 10;
pair<pair<int, int>, int> a[N], b[N];
bool mark[N];
vector<pair<int, int> > v;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  long long ans = inf, sum = 0;
  cin >> n >> k;
  if (k > n) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
    b[i].first.second = a[i].first.first;
    b[i].first.first = a[i].first.second;
    b[i].second = i;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  int point = a[n - k + 1].first.first;
  if (point + 2 <= n) {
    for (int i = 1; i <= point + 2; i++) sum += b[i].first.first;
    ans = sum;
  }
  sum = 0;
  if (point + 1 <= n) {
    int cnt = 0, t = 0;
    for (int i = n; i >= 1; i--)
      if (a[i].first.first > point + 1)
        cnt++;
      else if (a[i].first.first >= point)
        v.push_back({a[i].first.second, a[i].second});
      else
        break;
    sort(v.begin(), v.end());
    for (int i = v.size() - (k - 1 - cnt) - 1; i >= 0; i--)
      sum += v[i].first, mark[v[i].second] = true, t++;
    for (int i = 1; i <= n && t < point + 1; i++)
      if (!mark[b[i].second]) sum += b[i].first.first, t++;
    ans = min(ans, sum);
  }
  sum = 0;
  v.clear();
  memset(mark, 0, sizeof(mark));
  if (point <= n) {
    int cnt = 0, t = 0;
    for (int i = n; i >= 1; i--)
      if (a[i].first.first > point)
        cnt++;
      else if (a[i].first.first == point)
        v.push_back({a[i].first.second, a[i].second});
      else
        break;
    sort(v.begin(), v.end());
    for (int i = v.size() - (k - 1 - cnt) - 1; i >= 0; i--)
      sum += v[i].first, mark[v[i].second] = true, t++;
    for (int i = 1; i <= n && t < point; i++)
      if (!mark[b[i].second]) sum += b[i].first.first, t++;
    ans = min(ans, sum);
  }
  if (ans == inf)
    cout << -1;
  else
    cout << ans;
  return 0;
}

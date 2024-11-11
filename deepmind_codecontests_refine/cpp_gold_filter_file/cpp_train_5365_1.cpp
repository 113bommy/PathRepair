#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = (long long)1 << 62;
const int mod = 1e9 + 7;
const int maxn = 2000 + 5;
int n;
pair<long long, long long> a[maxn];
map<pair<long long, long long>, int> m;
long long ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      long long tx = a[i].first + a[j].first;
      long long ty = a[i].second + a[j].second;
      m[{tx, ty}]++;
    }
  for (auto u : m) ans += ((u.second) * (u.second - 1)) / 2;
  cout << ans;
  return 0;
}

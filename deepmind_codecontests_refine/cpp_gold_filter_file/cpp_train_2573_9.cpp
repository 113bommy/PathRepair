#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long n, m, a[maxn], k, pos, tmp, ans, cnt, d, z[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  k = n / m;
  vector<vector<long long>> v(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i] % m].push_back(i);
  }
  vector<pair<int, int>> b;
  while (cnt < 2 * m) {
    pos %= m;
    while (v[pos].size() > k) {
      tmp = v[pos].back();
      v[pos].pop_back();
      b.emplace_back(tmp, cnt);
    }
    while (v[pos].size() < k && b.size() > 0) {
      long long x = b.back().first;
      long long y = b.back().second;
      b.pop_back();
      v[pos].push_back(x);
      a[x] += (cnt - y);
      ans += (cnt - y);
    }
    ++pos;
    ++cnt;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) cout << a[i] << " ";
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, val, n, m, k, crt1 = 0, crt = 0;
  cin >> n >> m >> k;
  vector<ll> v(n + 2), times(m + 2), init(n + 2);
  for (int i = 1; i <= n; ++i) cin >> init[i];
  vector<tuple<int, int, int>> q;
  q.emplace_back(0, 0, 0);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> val;
    q.emplace_back(a, b, val);
  }
  for (int i = 0; i < k; ++i) {
    cin >> a >> b;
    times[a]++;
    times[b + 1]--;
  }
  for (int i = 1; i <= m; ++i) {
    crt1 += times[i];
    tie(a, b, val) = q[i];
    v[a] += crt1 * val;
    v[b + 1] -= crt1 * val;
  }
  for (int i = 1; i <= n; ++i) {
    crt += v[i];
    cout << init[i] + crt << ' ';
  }
  return 0;
}

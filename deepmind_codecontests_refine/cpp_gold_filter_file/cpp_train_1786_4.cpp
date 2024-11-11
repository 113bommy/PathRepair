#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const int32_t mod = 1e9 + 7;
const long long INF = 1e18;
const long long N = 1e5 + 5, M = 103;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> idx(n + 5, -1), q(m, 0);
  for (long long i = 0; i < m; i++) {
    cin >> q[i];
    amax(idx[q[i]], i);
  }
  long long total = 3 * n - 2;
  vector<long long> processed(n + 1, 0);
  for (long long i = 0; i < m; ++i) {
    if (processed[q[i]]) continue;
    processed[q[i]] = 1;
    --total;
    if (q[i] == 1) {
      if (idx[q[i] + 1] > i) --total;
    } else if (q[i] == n) {
      if (idx[q[i] - 1] > i) --total;
    } else {
      if (idx[q[i] + 1] > i) --total;
      if (idx[q[i] - 1] > i) --total;
    }
  }
  cout << total;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int MAX{2010};
const ll MOD{1000000007}, oo{1LL << 62};
ll as[MAX], bs[MAX];
pair<ll, vector<ii>> solve(int N, int M) {
  ll a = accumulate(as, as + N, 0LL);
  ll b = accumulate(bs, bs + M, 0LL);
  ll v = llabs(a - b);
  vector<ii> ans;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      auto value = llabs(a - b - 2 * (as[i] - bs[j]));
      if (value < v) {
        ans = vector<ii>{ii(i + 1, j + 1)};
        v = value;
      }
    }
  }
  map<ll, ii> xs;
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j) xs[2 * (as[i] + as[j])] = ii(i, j);
  for (int i = 0; i < M; ++i) {
    for (int j = i + 1; j < M; ++j) {
      auto z = a - b + 2 * (bs[i] + bs[j]);
      auto it = xs.lower_bound(z);
      if (it != xs.end()) {
        auto [m, n] = it->second;
        auto value = llabs(a - b - 2 * (as[m] - bs[i] + as[n] - bs[j]));
        if (value < v) {
          ans = vector<ii>{ii(m + 1, i + 1), ii(n + 1, j + 1)};
          v = value;
        }
      }
      if (it != xs.begin()) {
        --it;
        auto [m, n] = it->second;
        auto value = llabs(a - b - 2 * (as[m] - bs[i] + as[n] - bs[j]));
        if (value < v) {
          ans = vector<ii>{ii(m + 1, i + 1), ii(n + 1, j + 1)};
          v = value;
        }
      }
    }
  }
  return {v, ans};
}
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> as[i];
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) cin >> bs[i];
  auto ans = solve(N, M);
  cout << ans.first << '\n';
  cout << ans.second.size() << endl;
  for (auto [i, j] : ans.second) cout << i << ' ' << j << endl;
  return 0;
}

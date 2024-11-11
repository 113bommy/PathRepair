#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
ll a[500007];
constexpr ll inf = 10000000000000;
ll dp[2][5000][2];
int p(int i) { return i & 1; }
int o(int i) { return (i + 1) & 1; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int K, n;
  cin >> K >> n;
  vector<pair<ll, int>> A(n);
  vector<ll> inp(n);
  for (int i = 0; i < n; ++i) {
    cin >> inp[i];
  }
  sort(begin(inp), end(inp));
  for (int i = 0; i < n - 1; ++i) {
    ll v = inp[i + 1] - inp[i];
    A[i] = make_pair(v, i);
    a[i] = v;
  }
  sort(begin(A), end(A));
  set<int> cons;
  int i = 0;
  while ((int)(cons).size() < 3 * K && i < n - 1) {
    if (A[i].second > 0) cons.insert(A[i].second - 1);
    if (A[i].second < n - 2) cons.insert(A[i].second + 1);
    cons.insert(A[i].second);
    ++i;
  }
  vector<pair<ll, int>> sm;
  for (const auto &e : cons) {
    if (!sm.empty() && sm.back().second < e - 1) sm.emplace_back(inf, -1);
    sm.emplace_back(a[e], e);
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < K + 1; ++j) {
      for (int l = 0; l < 2; ++l) {
        dp[i][j][l] = inf;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 1; i <= (int)(sm).size(); ++i) {
    for (int j = 0; j <= K; ++j) {
      dp[p(i)][j][1] = dp[o(i)][j - 1][0] + sm[i - 1].first;
      dp[p(i)][j][0] = min(dp[o(i)][j][0], dp[o(i)][j][1]);
    }
  }
  cout << min(dp[p((int)(sm).size())][K][0], dp[p((int)(sm).size())][K][1])
       << endl;
}

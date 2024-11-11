#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
unordered_map<int, vector<pair<int, int> > > parts;
int K;
int dp[312];
int res[100100];
int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N >> K;
  for (int i = (0); i < (N); i++) {
    int a, b;
    cin >> a >> b;
    int id = b / K;
    if (id * K > b) --id;
    parts[id].push_back(make_pair(a, b));
    if (b % K) parts[id + 1].push_back(make_pair(a, b));
  }
  memset(res, 0, sizeof(res));
  memset(dp, 0, sizeof(dp));
  for (auto slices : parts) {
    vector<tuple<int, int, bool> > changeset;
    for (auto pt : slices.second) {
      changeset.push_back(make_tuple(pt.first, pt.second, 0));
      changeset.push_back(make_tuple(pt.first + K, pt.second, 1));
    }
    sort((changeset).begin(), (changeset).end());
    int F = slices.first * K;
    int T = F + K;
    int last = 0;
    for (auto change : changeset) {
      int x = get<0>(change);
      int y = get<1>(change);
      if (x != last) {
        for (int k = (0); k < (K); k++) res[dp[k]] += x - last;
        last = x;
      }
      int f = max(F, y);
      int t = min(T, y + K);
      int c = (get<2>(change) ? -1 : 1);
      for (int k = (f - F); k < (t - F); k++) dp[k] += c;
    }
  }
  for (int n = (1); n < (N + 1); n++) cout << res[n] << ((n == N) ? '\n' : ' ');
  return 0;
}

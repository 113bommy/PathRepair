#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
int N;
long long dp[MAXN + 5][MAXN + 5];
pair<long long, long long> task[MAXN + 5];
vector<long long> v[MAXN + 5];
const long long BASE = 10000;
bool check(long long avg) {
  v[0].clear();
  int i = 0, p = 0;
  while (i < N) {
    bool first = true;
    while (i < N && (first || task[i].first == task[i - 1].first)) {
      first = false;
      v[p].push_back(task[i].first - avg * task[i].second);
      i++;
    }
    sort(v[p].begin(), v[p].end());
    p++;
    v[p].clear();
  }
  sort(v[p].begin(), v[p].end());
  int M = p + 1;
  for (int i = 0; i <= N; i++) dp[M][i] = 0;
  for (int i = M - 1; i >= 0; i--) {
    for (int j = 0; j <= N; j++) {
      dp[i][j] = 1e18;
      long long sum = 0;
      for (long long d : v[i]) sum += d;
      for (int ch = v[i].size(); ch >= 0; ch--) {
        if (v[i].size() - ch > j) break;
        int spare = j - (v[i].size() - ch) + ch;
        if (spare > N) continue;
        dp[i][j] = min(dp[i][j], dp[i + 1][spare] + sum);
        if (ch > 0) sum -= v[i][ch - 1];
      }
    }
  }
  return dp[0][0] <= 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> task[i].first;
    task[i].first *= BASE;
  }
  for (int i = 0; i < N; i++) cin >> task[i].second;
  sort(task, task + N, greater<pair<long long, long long>>());
  long long l = 0.0, r = 1e12 + 5, ans = 0;
  while (l <= r) {
    long long m = (l + r) >> 1;
    if (check(m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans / 10 + (ans & 1LL) << "\n";
}

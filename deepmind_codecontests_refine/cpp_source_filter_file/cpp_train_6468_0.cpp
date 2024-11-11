#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long dp[101][101][101];
long long best[101];
long long profit[101];
vector<long long> grps;
string s;
int n;
void prep_best() {
  memset(best, 0, sizeof best);
  for (long long len = 1; len <= n; len++) {
    for (long long cut = 1; cut <= len; cut++) {
      best[len] = max(best[len], profit[cut] + best[len - cut]);
    }
  }
}
long long driver(long long i, long long j, long long extras) {
  if (i > j) return 0;
  if (dp[i][j][extras] != -1) return dp[i][j][extras];
  long long res = best[grps[i] + extras] + driver(i + 1, j, 0);
  for (long long group = i + 2; group <= j; group++) {
    res = max(res,
              driver(i + 1, group - 1, 0) + driver(group, j, extras + grps[i]));
  }
  return dp[i][j][extras] = res;
}
void solve() {
  cin >> n >> s;
  for (long long i = 1; i <= n; i++) cin >> profit[i];
  prep_best();
  grps.clear();
  long long consec = 0;
  for (long long i = 0; i < n; i++) {
    if (i == 0)
      consec++;
    else {
      if (s[i] == s[i - 1])
        consec++;
      else {
        grps.push_back(consec);
        consec = 1;
      }
    }
  }
  grps.push_back(consec);
  memset(dp, -1, sizeof dp);
  cout << driver(0, grps.size() - 1, 0);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

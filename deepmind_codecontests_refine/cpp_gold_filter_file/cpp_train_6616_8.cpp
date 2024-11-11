#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e3 + 10;
const long long INF = 1e17 + 10;
vector<long long> dp[MAXN];
vector<long long> possible[MAXN];
long long a[MAXN];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; i++) {
    possible[i].push_back(a[i]);
    for (long long j = 0; j < possible[i - 1].size(); j++) {
      possible[i].push_back(possible[i - 1][j] + 1);
    }
  }
  for (long long i = n; i >= 1; i--) {
    for (long long j = 0; j < possible[i + 1].size(); j++) {
      possible[i].push_back(possible[i + 1][j] - 1);
    }
    sort(possible[i].begin(), possible[i].end());
    possible[i].resize(unique(possible[i].begin(), possible[i].end()) -
                       possible[i].begin());
  }
  possible[0].push_back(-INF);
  dp[0].push_back(0);
  for (long long i = 1; i <= n; i++) {
    long long p = 0, e = INF;
    for (long long j = 0; j < possible[i].size(); j++) {
      while (p < possible[i - 1].size() &&
             possible[i - 1][p] < possible[i][j]) {
        e = min(e, dp[i - 1][p]);
        p++;
      }
      dp[i].push_back(e + abs(a[i] - possible[i][j]));
    }
  }
  long long res = INF;
  for (long long i = 0; i < dp[n].size(); i++) {
    res = min(res, dp[n][i]);
  }
  cout << res;
}

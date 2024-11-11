#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n;
long long x[200000 + 10], y[100000 + 10];
long long dp[200000 + 10][2];
map<long long, vector<long long> > h;
map<long long, long long> h1;
map<long long, long long> h2;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    h[max(x[i], y[i])].push_back(i);
  }
  for (auto it = h.begin(); it != h.end(); it++) {
    long long mnx = 1e9 + 10, mny = 1e9 + 10;
    for (auto it1 = (*it).second.begin(); it1 != (*it).second.end(); it1++) {
      mnx = min(mnx, x[(*it1)] - y[(*it1)]);
      mny = min(mny, y[(*it1)] - x[(*it1)]);
    }
    for (auto it1 = (*it).second.begin(); it1 != (*it).second.end(); it1++) {
      if (x[(*it1)] - y[(*it1)] == mnx) {
        h1[(*it).first] = (*it1);
      }
      if (y[(*it1)] - x[(*it1)] == mny) {
        h2[(*it).first] = (*it1);
      }
    }
  }
  long long i = 0;
  for (auto it = h1.begin(); it != h1.end(); it++) {
    long long j = (*it).first;
    if (i == 0) {
      dp[i][0] = x[h2[j]] + y[h2[j]] + abs(x[h2[j]] - x[h1[j]]) +
                 abs(y[h2[j]] - y[h1[j]]);
      dp[i][1] = x[h1[j]] + y[h1[j]] + abs(x[h2[j]] - x[h1[j]]) +
                 abs(y[h2[j]] - y[h1[j]]);
    } else {
      it--;
      auto it1 = it;
      long long j1 = (*it1).first;
      dp[i][0] = min(
          dp[i - 1][0] + abs(x[h2[j]] - x[h1[j1]]) + abs(y[h2[j]] - y[h1[j1]]),
          dp[i - 1][1] + abs(x[h2[j]] - x[h2[j1]]) + abs(y[h2[j]] - y[h2[j1]]));
      dp[i][0] += abs(x[h2[j]] - x[h1[j]]) + abs(y[h2[j]] - y[h1[j]]);
      dp[i][1] = min(
          dp[i - 1][0] + abs(x[h1[j]] - x[h1[j1]]) + abs(y[h1[j]] - y[h1[j1]]),
          dp[i - 1][1] + abs(x[h1[j]] - x[h2[j1]]) + abs(y[h1[j]] - y[h2[j1]]));
      dp[i][1] += abs(x[h2[j]] - x[h1[j]]) + abs(y[h2[j]] - y[h1[j]]);
      it++;
    }
    i++;
  }
  cout << min(dp[i - 1][0], dp[i - 1][1]) << '\n';
  return 0;
}

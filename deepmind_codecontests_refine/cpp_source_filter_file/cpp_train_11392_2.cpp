#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
long long dp[3001][2];
long long mi[3001];
int main(void) {
  int n;
  cin >> n;
  vector<pair<long long, long long> > input;
  for (int i = (0); i < (int)(n); ++i) {
    long long a, b;
    cin >> a >> b;
    input.push_back(pair<long long, long long>(a, b));
  }
  sort(input.begin(), input.end());
  for (int i = (0); i < (int)(3001); ++i) mi[i] = 100000000000000000;
  dp[0][0] = (long long)input[0].second;
  mi[0] = (long long)input[0].second;
  for (int i = (1); i < (int)(n); ++i) {
    for (int j = (0); j < (int)(i); ++j) {
      dp[i][j] = (long long)dp[i - 1][j] +
                 (long long)abs((long long)input[i].first - input[j].first);
      mi[i] = (long long)min(mi[i], dp[i][j]);
    }
    dp[i][i] = (long long)mi[i - 1] + (long long)input[i].second;
    mi[i] = (long long)min(mi[i], dp[i][i]);
  }
  cout << mi[n - 1] << endl;
  return 0;
}

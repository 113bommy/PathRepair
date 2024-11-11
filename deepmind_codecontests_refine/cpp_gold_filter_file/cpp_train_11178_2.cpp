#include <bits/stdc++.h>
using namespace std;
vector<pair<long double, long long int> > coord1;
vector<long long int> temp;
long long int dp[5005][5005];
long long int lnds(long long int i, long long int j) {
  if (i == temp.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (temp[i] >= j)
    return dp[i][j] = max(lnds(i + 1, j), 1 + lnds(i + 1, temp[i]));
  else
    return lnds(i + 1, j);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, a, ans = 0, count = 0, prev = 0;
  long double b;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    coord1.push_back(make_pair(b, a - 1));
  }
  sort(coord1.begin(), coord1.end());
  for (int i = 0; i < coord1.size(); i++) temp.push_back(coord1[i].second);
  memset(dp, -1, sizeof(dp));
  cout << n - lnds(0, 0) << endl;
  return 0;
}

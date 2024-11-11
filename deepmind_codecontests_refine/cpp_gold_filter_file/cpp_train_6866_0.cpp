#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, a, n) for(int i = (int)a; i < (int)n; i++)
#define REP(i, n) FOR(i, 0, n)
using namespace	std;

int n, m;

int solve(vector<int>& c, vector<int>& a) {
  vector<int> dp(m + 1, 0);
  FOR(i, 1, m + 1) REP(j, n)
    if(c[j] <= i)
      dp[i] = max(dp[i], dp[i - c[j]] + a[j]);
  return dp.back();
}

int main() {
  string name;
  while(cin >> n >> m) {
    vector<int>	c(n), v(n), d(n), l(n);
    REP(i, n) {
      cin.ignore(), getline(cin, name);
      cin >> c[i] >> v[i] >> d[i] >> l[i];
    }
    cout << max({solve(c, v), solve(c, d), solve(c, l)}) << endl;
  }
  return 0;
}


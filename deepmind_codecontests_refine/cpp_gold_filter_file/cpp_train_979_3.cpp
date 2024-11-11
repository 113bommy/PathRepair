#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int INFF = 1e17;
const double EPS = 1e-9;
const long long int MOD = 1e9 + 7;
const int MAXN = 1e2 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, sum1 = 0, sum2 = 0, iter = 0;
  vector<vector<int> > p(MAXN);
  vector<int> s;
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    int t1;
    cin >> t1;
    p[i].resize(t1);
    for (int j = (0); j < (t1); ++j) cin >> p[i][j];
  }
  for (int i = (0); i < (n); ++i) {
    if (!(p[i].size() % 2)) {
      for (int j = (0); j < (p[i].size() / 2); ++j) sum1 += p[i][j];
      for (int j = (p[i].size() / 2); j < (p[i].size()); ++j) sum2 += p[i][j];
    } else {
      for (int j = (0); j < (p[i].size() / 2); ++j) sum1 += p[i][j];
      for (int j = ((p[i].size() / 2) + 1); j < (p[i].size()); ++j)
        sum2 += p[i][j];
      s.push_back(p[i][p[i].size() / 2]);
    }
  }
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  for (auto u : s) {
    if (!(iter % 2))
      sum1 += u;
    else
      sum2 += u;
    iter++;
  }
  cout << sum1 << " " << sum2 << '\n';
  return 0;
}

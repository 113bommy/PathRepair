#include <bits/stdc++.h>
using namespace std;
const int maxm = 21;
const int maxn = 110;
const long long int INF = 1e18 + 1e17 * 5;
vector<pair<long long int, pair<long long int, long long int> > > person;
long long int Ans = INF, dp[1 << maxm], n, m, b;
int main() {
  cin >> n >> m >> b;
  for (int i = 1; i <= n; i++) {
    long long int x, y, z, mask = 0;
    cin >> x >> y >> z;
    for (long long int j = 1; j <= z; j++) {
      long long int problem;
      cin >> problem;
      mask |= (1 << (problem - 1));
    }
    person.push_back(make_pair(y, make_pair(x, mask)));
  }
  sort(person.begin(), person.end());
  fill(dp, dp + (1 << maxm), INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    long long int PP = person[i].second.second;
    for (int j = (1 << m) - 1; j >= 0; j--)
      dp[j | PP] = min(dp[j | PP], dp[j] + person[i].second.first);
    Ans = min(Ans, (dp[((1 << m)) - 1] + (person[i].first * b)));
  }
  cout << (Ans != INF ? Ans : -1);
  return 0;
}

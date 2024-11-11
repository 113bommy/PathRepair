#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> P[200001];
vector<pair<pair<long long, long long>, int> > Dis;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> P[i].first >> P[i].second;
    if (i)
      Dis.push_back(
          {{P[i].first - P[i - 1].second, P[i].second - P[i - 1].first},
           i - 1});
  }
  sort(Dis.begin(), Dis.end());
  reverse(Dis.begin(), Dis.end());
  int res[n];
  set<pair<long long, int> > S;
  set<pair<long long, int> >::iterator it;
  long long x;
  for (int i = 0; i < m; i++) {
    cin >> x;
    S.insert({x, i});
  }
  for (int i = 0; i < n - 1; i++) {
    it = S.upper_bound(make_pair(Dis[i].first.second, 1E9 + 1));
    if (it == S.begin()) {
      cout << "NO";
      return 0;
    }
    it--;
    if ((*it).first < Dis[i].first.first) {
      cout << "NO";
      return 0;
    }
    res[Dis[i].second] = (*it).second;
    S.erase(*it);
  }
  cout << "YES\n";
  for (int i = 0; i < n - 1; i++) cout << res[i] + 1 << " ";
  return 0;
}

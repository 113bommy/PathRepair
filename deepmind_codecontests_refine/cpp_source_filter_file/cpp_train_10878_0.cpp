#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
const int mx = 1e5;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<pair<char, int>> log(n);
  set<int> enter, second;
  for (int i = 0; i < n; ++i) {
    cin >> log[i].first >> log[i].second;
    if (log[i].first == '+')
      enter.insert(log[i].second);
    else if (!enter.count(log[i].first))
      second.insert(log[i].second);
  }
  int res = (int)(second).size();
  for (const auto &p : log) {
    if (p.first == '+')
      second.insert(p.second);
    else
      second.erase(p.second);
    res = max(res, (int)(second).size());
  }
  cout << res << '\n';
}

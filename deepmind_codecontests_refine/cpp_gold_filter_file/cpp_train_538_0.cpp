#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long int l[N], r[N];
vector<long long int> ans;
vector<pair<long long int, long long int>> v[N];
multiset<pair<long long int, long long int>> s;
int main() {
  long long int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    v[l[i] - 1].push_back(make_pair(r[i] - 1, i + 1));
  }
  for (int i = 0; i < 3e5; i++) {
    for (auto u : v[i]) {
      s.insert(make_pair(u.first, u.second));
    }
    while (s.size() > 0) {
      pair<long long int, long long int> pp = *s.begin();
      if (pp.first < i) {
        s.erase(pp);
      } else
        break;
    }
    while (s.size() > k) {
      pair<long long int, long long int> pp = *s.rbegin();
      ans.push_back(pp.second);
      s.erase(pp);
    }
  }
  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (int u : ans) cout << u << ' ';
}

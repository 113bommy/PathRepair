#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, d, k;
  cin >> n >> d >> k;
  if (d >= n) {
    cout << "NO\n";
    return 0;
  }
  vector<pair<int, int>> e;
  vector<int> deg(n + 1, 0);
  set<tuple<int, int, int>> s;
  for (int i = 1; i <= d; i++) {
    deg[i]++;
    deg[i + 1]++;
    if (deg[i] > k or deg[i + 1] > k) {
      cout << "NO\n";
      return 0;
    }
    e.emplace_back(i, i + 1);
    s.insert({deg[i], max(i - 1, d + 1 - i), i});
    if (i < d) continue;
    s.insert({deg[i + 1], max(i, d - i - 1), i});
  }
  for (int i = d + 2; i <= n; i++) {
    while (!s.empty() and
           (get<0>(*s.begin()) == k or get<1>(*s.begin()) == d)) {
      s.erase(s.begin());
    }
    if (s.empty()) {
      cout << "NO\n";
      return 0;
    }
    int cd, dist, v;
    tie(cd, dist, v) = *s.begin();
    s.erase(s.begin());
    cd++;
    s.insert({cd, dist, v});
    deg[i]++;
    s.insert({deg[i], dist + 1, i});
    e.emplace_back(v, i);
  }
  cout << "YES\n";
  for (auto &x : e) {
    cout << x.first << ' ' << x.second << '\n';
  }
}

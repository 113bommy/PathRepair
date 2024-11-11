#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  multiset<pair<int, int>> m;
  int a[n], e[n];
  for (int i = 0, j; i < n; i++) cin >> a[i];
  long long int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> e[i];
    total += e[i];
    m.insert(make_pair(a[i], e[i]));
  }
  multiset<int, greater<int>> w;
  long long int ans = INT_MAX;
  for (auto it = m.begin(); it != m.end();) {
    long long int cnt = 0, sub = 0;
    auto it1 = it;
    while (it1 != m.end() && it1->first == it->first) {
      sub = sub + it1->second;
      cnt++;
      it1++;
    }
    if (cnt > 1) {
      long long int temp = 0;
      auto it2 = w.begin();
      while (temp < cnt - 1 && it2 != w.end()) {
        sub = sub + (*it2);
        temp++;
        it2++;
      }
    }
    ans = min(ans, total - sub);
    it1 = it;
    while (it1 != m.end() && it1->first == it->first) {
      w.insert(it1->second);
      it1++;
    }
    it = it1;
  }
  cout << ans;
  return 0;
}

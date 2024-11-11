#include <bits/stdc++.h>
using namespace std;
bool mycomp(pair<int, int> p1, pair<int, int> p2) {
  return p1.second > p2.second;
}
int main() {
  vector<pair<int, int>> v;
  int n, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back({i, a});
  }
  sort(v.begin(), v.end(), mycomp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += i * v[i].second + 1;
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << v[i].first << " ";
  }
  cout << "\n";
}

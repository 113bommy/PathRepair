#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  vector<pair<int, int>> v;
  cin >> n;
  for (int i = 1; i <= n && cin >> x; i++) v.push_back({x, i});
  sort(v.begin(), v.end());
  cout << v[n - 2].second << " " << v[n - 2].first;
}

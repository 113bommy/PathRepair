#include <bits/stdc++.h>
using namespace std;

int main() {
  using P = pair<int, int>;
  int n;
  cin >> n;
  vector<P> v(n);
  for (auto &p : v) cin >> p.first >> p.second;
  sort(v.begin(), v.end());
  cout << v[n - 1].first + v[n - 1].second << endl;
  return 0;
}

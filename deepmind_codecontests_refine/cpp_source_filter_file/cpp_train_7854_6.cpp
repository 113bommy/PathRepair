#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (v[i].second >= ans) {
      ans = v[i].second;
    } else {
      ans = v[i].first;
    }
  }
  cout << ans << endl;
}

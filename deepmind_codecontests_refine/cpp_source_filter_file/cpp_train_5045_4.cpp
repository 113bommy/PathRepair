#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  int prev = INT_MAX;
  for (auto x : v) {
    if (prev >= x.second)
      prev = x.second;
    else
      prev = x.first;
  }
  cout << prev << '\n';
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v.push_back(make_pair(a, i));
  }
  sort(v.begin(), v.end());
  int c = 0;
  for (int i = 0; i < n && k >= v[i].first; ++i, ++c) {
    k -= v[i].first;
  }
  cout << c << '\n';
  for (int i = 0; i < c; ++i) {
    cout << v[i].second << ' ';
  }
}

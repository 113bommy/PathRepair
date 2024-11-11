#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, val;
  vector<pair<int, int> > v, v1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    v.push_back(make_pair(val, i + 1));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int prev = -1, prevpos = -1;
  for (int i = 0; i < n; i++) {
    if (v[i].first == prev) {
      v1.push_back(make_pair(v[i].second, prevpos));
    } else {
      v1.push_back(make_pair(v[i].second, i + 1));
      prevpos = i + 1;
      prev = v[i].first;
    }
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < n; i++) cout << v1[i].second << " ";
  cout << endl;
  return 0;
}

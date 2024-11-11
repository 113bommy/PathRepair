#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  for (int i = 1; i < n; i++) {
    vec.push_back({i, i + 1});
  }
  for (int i = 1; i < n - 2; i++) {
    for (int j = i + 3; j <= n; j += 2) {
      vec.push_back({i, j});
    }
  }
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i].first << " " << vec[i].second << endl;
  }
}

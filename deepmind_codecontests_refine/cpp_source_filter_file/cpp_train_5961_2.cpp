#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  vec.push_back({0, 0});
  vec.push_back({0, 1});
  int u = 1, v = 0;
  int cnt = 0;
  for (int i = 1; i <= n + 1; i++) {
    vec.push_back({i, cnt});
    vec.push_back({i, cnt + 1});
    if (i != n) vec.push_back({i, cnt + 2});
    cnt++;
  }
  cout << vec.size() << endl;
  for (auto x : vec) {
    cout << x.first << " " << x.second << endl;
  }
}

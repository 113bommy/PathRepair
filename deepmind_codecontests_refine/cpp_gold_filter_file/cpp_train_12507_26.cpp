#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<pair<int, int>> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  int hh;
  cin >> hh;
  int cnt = 0;
  for (auto e : v) {
    if (e.second < hh) cnt++;
  }
  cout << n - cnt;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  cin.ignore();
  string s;
  getline(cin, s);
  istringstream l1(s);
  getline(cin, s);
  istringstream l2(s);
  vector<vector<int>> vv(k);
  int a, b;
  for (int i = 0; i < n; i++) {
    l1 >> a;
    l2 >> b;
    vv[a - 1].push_back(b);
  }
  int remaining = 0;
  vector<int> times;
  for (auto &v : vv) {
    if (v.size()) {
      sort(v.begin(), v.end());
      v.pop_back();
      for (int t : v) times.push_back(t);
    } else {
      remaining++;
    }
  }
  sort(times.begin(), times.end());
  long long ans = 0;
  for (int i = 0; i < remaining; i++) {
    ans += times[i];
  }
  cout << ans;
}

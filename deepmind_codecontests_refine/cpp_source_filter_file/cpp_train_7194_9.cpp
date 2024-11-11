#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> vals;
  vals.push_back(0);
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    vals.push_back(v);
  }
  vals.push_back(1001);
  int res = 0;
  int cur = 1;
  for (int i = 1; i < vals.size(); ++i) {
    if (vals[i] == vals[i - 1] + 1)
      ++cur;
    else {
      res += max(0, cur - 2);
      cur = 1;
    }
  }
  res += max(0, cur - 2);
  cout << res << '\n';
}

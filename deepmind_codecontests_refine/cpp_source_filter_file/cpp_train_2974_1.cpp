#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> v;
  for (int i = 0; i < n - 2; ++i) {
    if (s.substr(i, 3) == "ogo") {
      int j = i + 1;
      while (j + 2 < n - 1 && s.substr(j + 2, 2) == "go") j += 2;
      v.push_back(pair<int, int>(i, j + 2 - i));
      i = j + 2;
    }
  }
  string ans = "";
  int cur = 0;
  for (int i = 0; i < v.size(); ++i) {
    ans += s.substr(cur, v[i].first - cur) + "***";
    cur = v[i].first + v[i].second;
  }
  if (cur < n) ans += s.substr(cur, n - cur);
  cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, d, a;
  cin >> n >> m >> d;
  set<pair<int, int> > s;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    s.insert({a, i});
  }
  vector<int> res;
  res.resize(n);
  int day = 0;
  while (!s.empty()) {
    day++;
    pair<int, int> top = *s.begin();
    s.erase(top);
    int minute = top.first;
    res[top.second] = day;
    while (minute + d + 1 <= m) {
      auto p = s.lower_bound({minute + d + 1, 0});
      if (p == s.end()) break;
      top = *p;
      minute = top.first;
      res[top.second] = day;
      s.erase(*p);
    }
  }
  cout << day << endl;
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
}

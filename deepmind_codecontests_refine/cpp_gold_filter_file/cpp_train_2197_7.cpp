#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  set<pair<int, int> > a;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.insert({tmp, i});
  }
  int curt = -d;
  int day = 0;
  while (!a.empty()) {
    auto next = a.upper_bound({curt + d, n});
    auto f = a.begin();
    if (next != a.end() && next->first <= m) {
      curt = next->first;
      ans[next->second] = day;
      a.erase(next);
    } else {
      day++;
      curt = f->first;
      ans[f->second] = day;
      a.erase(f);
    }
  }
  cout << day + 1 << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << ' ';
  }
  return 0;
}

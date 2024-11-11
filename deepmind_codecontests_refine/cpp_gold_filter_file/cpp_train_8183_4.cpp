#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> s;
  int last = n + 1;
  vector<int> ans(1, 1);
  for (int i = 0; i < n; ++i) {
    int pos;
    cin >> pos;
    s.insert(pos);
    for (auto e = (--s.lower_bound(last)); distance(s.begin(), e) >= 0; --e) {
      if (*e == last - 1)
        last--;
      else
        break;
      if (distance(s.begin(), e) == 0) break;
    }
    ans.push_back(s.size() - n + last);
  }
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}

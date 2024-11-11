#include <bits/stdc++.h>
using namespace std;
int book[100010];
vector<pair<int, int>> v;
deque<int> high, low;
int main() {
  int n, k, ans = 0, num = 0, r, l;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> book[i];
  for (r = 1, l = 1; r <= n; r++) {
    while (!high.empty() && high.back() < book[r]) high.pop_back();
    high.push_back(book[r]);
    while (!low.empty() && low.back() > book[r]) low.pop_back();
    low.push_back(book[r]);
    while (!high.empty() && !low.empty() && high.front() - low.front() > k) {
      if (v.empty()) {
        num = 1;
        ans = r - l;
        v.push_back(make_pair(l, r - 1));
      } else if (r - l > ans) {
        v.clear();
        num = 1;
        ans = r - l;
        v.push_back(make_pair(l, r - 1));
      } else if (!v.empty() && r - l == ans) {
        num++;
        v.push_back(make_pair(l, r - 1));
      }
      if (high.front() == book[l]) high.pop_front();
      if (low.front() == book[l]) low.pop_front();
      l++;
    }
  }
  while (l <= n) {
    if (v.empty()) {
      num = 1;
      ans = r - l;
      v.push_back(make_pair(l, r - 1));
    } else if (r - l > ans) {
      v.clear();
      num = 1;
      ans = r - l;
      v.push_back(make_pair(l, r - 1));
    } else if (!v.empty() && r - l == ans) {
      num++;
      v.push_back(make_pair(l, r - 1));
    }
    if (high.front() == book[l]) high.pop_front();
    if (low.front() == book[l]) low.pop_front();
    l++;
  }
  cout << ans << " " << num << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << endl;
  return 0;
}

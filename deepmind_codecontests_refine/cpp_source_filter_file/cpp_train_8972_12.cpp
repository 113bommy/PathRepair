#include <bits/stdc++.h>
using namespace std;
int n;
long long area(int a, int b, int c) {
  cout << "1 " << a << ' ' << b << ' ' << c << endl;
  int ans;
  cin >> ans;
  return ans;
}
int check(int a, int b, int c) {
  cout << "2 " << a << ' ' << b << ' ' << c << endl;
  int ans;
  cin >> ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  int pos = 2;
  for (int i = 3; i <= n; ++i)
    if (check(1, pos, i) == -1) pos = i;
  vector<pair<long long, int>> areas;
  for (int i = 2; i <= n; ++i)
    if (i != pos) areas.push_back({area(1, pos, i), i});
  sort(areas.begin(), areas.end());
  deque<int> ans;
  ans.push_back(areas[n - 3].second);
  for (int i = n - 4; i >= 0; --i) {
    if (check(1, areas[n - 3].second, areas[i].second) == 1)
      ans.push_back(areas[i].second);
    else
      ans.push_front(areas[i].second);
  }
  cout << "0 1 " << pos;
  while (!ans.empty()) {
    cout << ' ' << ans.front();
    ans.pop_front();
  }
}

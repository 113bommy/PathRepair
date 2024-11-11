#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
const int mod = 998244353;
int dcmp(long double x, long double y) {
  return fabs(x - y) <= 1e-12 ? 0 : x < y ? -1 : 1;
}
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int n;
int a[25 * 100 * 100 + 5];
priority_queue<pair<int, int>> pq;
set<pair<int, int>> vis;
int main() {
  fast();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
    } else {
      pq.push({cnt, -(i - cnt)});
      vis.insert({i - cnt, cnt});
      cnt = 1;
    }
  }
  int ans = 0;
  while (pq.size() && vis.size()) {
    auto cur = pq.top();
    pq.pop();
    cur.second *= -1;
    if (vis.find({cur.second, cur.first}) == vis.end()) continue;
    ans++;
    vis.erase({cur.second, cur.first});
    auto right = vis.upper_bound({cur.second, cur.first});
    if (right == vis.end() || right == vis.begin()) continue;
    auto left = right;
    left--;
    if (a[(*left).first] == a[(*right).first]) {
      int tot = (*left).second + (*right).second;
      int l = (*left).first;
      pq.push({tot, -l});
      vis.erase(left);
      vis.erase(right);
      vis.insert({l, tot});
    }
  }
  cout << ans << '\n';
  return 0;
}

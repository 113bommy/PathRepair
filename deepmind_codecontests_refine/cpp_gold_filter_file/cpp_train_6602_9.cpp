#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[100005];
map<int, vector<int>> block;
vector<int> row;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + m);
  for (int i = 0; i < m; i++) {
    row.push_back(a[i].first);
    row.push_back(a[i].first + 1);
    block[a[i].first].push_back(a[i].second);
  }
  row.push_back(1);
  row.push_back(n);
  sort(row.begin(), row.end());
  row.resize(unique(row.begin(), row.end()) - row.begin());
  while (!row.empty() && row.back() > n) {
    row.pop_back();
  }
  vector<pair<int, int>> cur = {{1, 1}};
  for (int i = 0; i < row.size(); i++) {
    vector<pair<int, int>> pre;
    swap(cur, pre);
    int x = row[i];
    int pre_y = 0;
    block[x].push_back(n + 1);
    for (int y : block[x]) {
      if (pre_y + 1 <= y - 1) {
        cur.push_back({pre_y + 1, y - 1});
      }
      pre_y = y;
    }
    vector<pair<int, int>> avail_cur;
    for (int i = 0, j = 0; i < cur.size(); i++) {
      while (j < pre.size() && pre[j].second < cur[i].first) {
        j++;
      }
      if (j == pre.size()) continue;
      pair<int, int> range = {max(pre[j].first, cur[i].first), cur[i].second};
      if (range.first <= range.second) {
        avail_cur.push_back(range);
      }
    }
    cur = avail_cur;
  }
  if (!cur.empty() && cur.back().second == n) {
    cout << 2 * n - 2 << "\n";
  } else {
    cout << "-1\n";
  }
  return 0;
}

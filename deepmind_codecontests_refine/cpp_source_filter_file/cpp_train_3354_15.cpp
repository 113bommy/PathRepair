#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 2;
const int M = 1e9 + 7;
vector<int> pos[N];
int x[N];
int bits[N], bitf[N];
int mn[N], mx[N];
int visit[N];
void update(int id, int add, int *bit) {
  for (; id < N; id += (id & (-id))) bit[id] += add;
}
int query(int id, int *bit) {
  int s = 0;
  for (; id; id -= (id & (-id))) s += bit[id];
  return s;
}
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x[i];
    pos[x[i]].push_back(i + 1);
  }
  for (int i = 1; i <= n; ++i) mn[i] = i, pos[i].push_back(m);
  vector<pair<int, pair<int, int>>> diff;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < pos[i].size(); ++j) {
      if (j)
        diff.push_back({-pos[i][j - 1], {pos[i][j], i}});
      else
        diff.push_back({1, {pos[i][j], i}});
    }
  }
  sort(diff.begin(), diff.end());
  for (int i = 0; i < diff.size(); ++i) {
    if (diff[i].first <= 0) {
      mx[diff[i].second.second] = max(
          mx[diff[i].second.second], diff[i].second.first + diff[i].first -
                                         query(diff[i].second.first - 1, bitf) +
                                         query(-diff[i].first, bitf));
      update(diff[i].second.first, 1, bitf);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (visit[x[i]]) continue;
    mn[x[i]] = 1;
    mx[x[i]] = max(mx[x[i]], x[i] + query(x[i], bits));
    visit[x[i]] = 1;
    update(1, 1, bits);
    update(x[i], -1, bits);
  }
  for (int i = 1; i <= n; ++i) {
    if (!visit[i]) mx[i] = i + query(i, bits);
  }
  for (int i = 1; i <= n; ++i) {
    cout << mn[i] << ' ' << mx[i] << '\n';
  }
}

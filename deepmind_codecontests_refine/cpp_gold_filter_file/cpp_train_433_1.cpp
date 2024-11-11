#include <bits/stdc++.h>
using namespace std;
int out(int x, int a, int b) { return x < a || x > b; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(2 * n);
  int second = 0, shere;
  for (int i = 0; i < 2 * n; ++i) cin >> x[i], second += x[i];
  sort(x.begin(), x.end());
  vector<pair<int, int> > sum(1300000);
  for (int i = 1; i < 1300000; ++i) sum[i] = {1000000007, -1000000007};
  sum[0] = {0, 0};
  int ans = 1000000007;
  vector<pair<int, int> > bst(1300000);
  int many = 0, pos = 0;
  shere = second;
  for (int i = 2 * n - 1; i >= 1; --i) {
    int sall = second - x[i] - x[0];
    int mov_r = shere - x[i] - x[0];
    vector<pair<int, int> > cur(1300000);
    for (int j = 0; j + mov_r < 1300000; ++j) {
      cur[j + mov_r] = {sum[j].first + i - 1, sum[j].second + i - 1};
    }
    int enter = 0;
    for (int j = 0; j < 1300000; ++j) {
      if (cur[j].first >= 1000000007 || out(n - 1, cur[j].first, cur[j].second))
        continue;
      if (max(j, sall - j) + x[0] + x[i] < ans) {
        ans = max(j, sall - j) + x[0] + x[i];
        enter = 1;
        many = n - i;
        pos = j;
      }
    }
    if (enter) bst = cur;
    for (int j = 1300000 - x[i] - 1; j >= 0; --j) {
      if (sum[j].first == 1000000007) continue;
      sum[j + x[i]].first = min(sum[j + x[i]].first, sum[j].first + 1);
      sum[j + x[i]].second = max(sum[j + x[i]].second, sum[j].second + 1);
    }
    shere -= x[i];
  }
  vector<int> up, down;
  vector<int> vis(2 * n);
  for (int i = 0; i < n - many; ++i) up.push_back(x[i]), vis[i] = 1;
  for (int i = 2 * n - 1, put = 0; i >= 0 && many; --i) {
    if (pos - x[i] >= 0 &&
        !out(n - 2 - put, bst[pos - x[i]].first, bst[pos - x[i]].second)) {
      many--;
      put++;
      pos -= x[i];
      up.push_back(x[i]);
      vis[i] = 1;
    }
  }
  for (int i = 0; i < 2 * n; ++i)
    if (!vis[i]) down.push_back(x[i]);
  sort(up.begin(), up.end());
  sort(down.rbegin(), down.rend());
  for (int i = 0; i < n; ++i) cout << up[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; ++i) cout << down[i] << ' ';
  cout << '\n';
}

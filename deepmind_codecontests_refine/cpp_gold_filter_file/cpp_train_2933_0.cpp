#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {0, -1, 0, 1, 1, -1, -1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int M = (1 << 9) + 5, N = 1e5 + 5;
int n, m;
int cnt[M];
vector<pair<int, int> > cost[M];
void gogo() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int num;
    cin >> num;
    int mask = 0;
    for (int j = 0; j < num; ++j) {
      int val;
      cin >> val;
      --val;
      mask |= (1 << val);
    }
    ++cnt[mask];
  }
  for (int i = 1; i <= m; ++i) {
    int c, num, mask = 0;
    cin >> c >> num;
    for (int j = 0; j < num; ++j) {
      int x;
      cin >> x;
      --x;
      mask |= (1 << x);
    }
    cost[mask].push_back(make_pair(c, i));
  }
  for (int i = 0; i < (1 << 9); ++i) sort((cost[i]).begin(), (cost[i]).end());
  pair<int, int> ans = make_pair(0, 2e9 + 1);
  int ans1, ans2;
  for (int i = 0; i < (1 << 9); ++i) {
    for (int j = 0; j < (1 << 9); ++j) {
      if (i != j) {
        if (!((int)(cost[i]).size()) || !((int)(cost[j]).size())) continue;
        int tmp = 0, a = cost[i][0].first, b = cost[j][0].first;
        int mask = (i | j);
        for (int k = 0; k < (1 << 9); ++k) {
          if ((mask | k) == mask) tmp += cnt[k];
        }
        if (ans.first == tmp) {
          if (ans.second > a + b) {
            ans1 = cost[i][0].second;
            ans2 = cost[j][0].second;
            ans.second = a + b;
          }
        } else if (ans < make_pair(tmp, a + b)) {
          ans = make_pair(tmp, a + b);
          ans1 = cost[i][0].second;
          ans2 = cost[j][0].second;
        }
      } else {
        if (((int)(cost[i]).size()) < 2) continue;
        int tmp = 0, a = cost[i][0].first, b = cost[i][1].first;
        int mask = (i | j);
        for (int k = 0; k < (1 << 9); ++k) {
          if ((mask | k) == mask) tmp += cnt[k];
        }
        if (ans.first == tmp) {
          if (ans.second > a + b) {
            ans1 = cost[i][0].second;
            ans2 = cost[i][1].second;
            ans.second = a + b;
          }
        } else if (ans < make_pair(tmp, a + b)) {
          ans = make_pair(tmp, a + b);
          ans1 = cost[i][0].second;
          ans2 = cost[i][1].second;
        }
      }
    }
  }
  cout << ans1 << ' ' << ans2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("sol"
            ".inp",
            "r")) {
    freopen(
        "sol"
        ".inp",
        "r", stdin);
    freopen(
        "sol"
        ".out",
        "w", stdout);
  }
  gogo();
}

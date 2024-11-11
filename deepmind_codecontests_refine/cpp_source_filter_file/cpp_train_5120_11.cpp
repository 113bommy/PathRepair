#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, inf = 0x3f3f3f3f, maxm = 3e4 + 10;
int n, r, dp[maxn][maxm];
struct Node {
  int need, add;
};
bool cmp1(const Node &a, const Node &b) {
  if (a.need != b.need) return a.need < b.need;
  return a.add > b.add;
}
bool cmp2(const Node &a, const Node &b) {
  return a.add + a.need > b.add + b.need;
}
void solve() {
  vector<Node> neg, pos;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (y >= 0)
      pos.push_back(Node{x, y});
    else
      neg.push_back(Node{max(x, -y), y});
  }
  sort(pos.begin(), pos.end(), cmp1);
  int ans1 = 0;
  for (int i = 0; i < pos.size(); ++i) {
    if (r >= pos[i].need) {
      r += pos[i].add;
      ++ans1;
    }
  }
  sort(neg.begin(), neg.end(), cmp2);
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < neg.size(); ++i) {
    for (int cr = 0; cr <= r; ++cr) {
      if (cr >= neg[i].need) {
        int j = cr + neg[i].add;
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][cr] + 1);
      }
      dp[i + 1][cr] = max(dp[i + 1][cr], dp[i][cr]);
    }
  }
  int ans2 = 0;
  for (int cr = 0; cr <= r; ++cr) {
    ans2 = max(ans2, dp[(int)neg.size()][cr]);
  }
  printf("%d\n", ans1 + ans2);
  return;
}
int main() {
  while (scanf("%d %d", &n, &r) != EOF) solve();
  return 0;
}

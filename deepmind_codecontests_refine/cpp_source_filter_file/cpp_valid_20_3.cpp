#include <bits/stdc++.h>
using namespace std;
int n, k;
struct node {
  int left;
  int right;
  int color;
  bool operator<(const node &b) const { return right > b.right; }
};
int t[10005];
int last[105], weight[10005];
bool vis[105];
pair<int, int> ans[105];
int main() {
  int x;
  vector<node> que;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n * k; i++) {
    scanf("%d", &x);
    if (last[x]) que.push_back((node){last[x], i, x});
    last[x] = i;
  }
  int limit = (n + k - 2) / (k - 1);
  sort(que.begin(), que.end());
  for (auto i : que) {
    if (vis[i.color]) continue;
    int times = 0;
    for (int j = i.left; j <= i.right; j++) times = max(times, weight[j]);
    if (times < limit) {
      ans[i.color] = make_pair(i.left, i.right);
      vis[i.color] = 1;
      for (int j = i.left; j <= i.right; j++) weight[j]++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}

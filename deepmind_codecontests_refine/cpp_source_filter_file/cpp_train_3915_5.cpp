#include <bits/stdc++.h>
using namespace std;
int pre[200010], d1[200010], d2[200010];
vector<int> v[200010];
int n, x, p1, p2;
void dfs(int now, int next, int step) {
  d1[now] = d2[now] = step;
  pre[now] = next;
  for (int i = 0; i < v[now].size(); i++) {
    int temp = v[now][i];
    if (temp != next) {
      dfs(temp, now, step + 1);
      d2[now] = max(d2[now], d2[temp]);
    }
  }
}
int main() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &p1, &p2);
    v[p1].push_back(p2);
    v[p2].push_back(p1);
  }
  dfs(1, 1, 0);
  int ans = 2 * d2[x];
  int k = x;
  for (int i = 0; i < d1[x]; i++) {
    if (i < d2[k]) {
      ans = max(2 * d2[k], ans);
    } else
      break;
    k = pre[k];
  }
  printf("%d\n", ans);
  return 0;
}

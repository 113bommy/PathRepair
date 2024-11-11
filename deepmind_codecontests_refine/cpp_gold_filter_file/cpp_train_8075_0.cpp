#include <bits/stdc++.h>
using namespace std;
int n, a[100005], num[100005][2];
vector<int> v[100005];
long long ans = 0;
void dfs(int now, int pre, int w) {
  int t = (a[now] >> w) & 1;
  num[now][t] = 1;
  num[now][t ^ 1] = 0;
  long long sum = 0;
  for (int i = 0; i < v[now].size(); i++) {
    int tt = v[now][i];
    if (tt == pre) continue;
    dfs(tt, now, w);
    sum += num[now][0] * num[tt][1] + num[now][1] * num[tt][0];
    num[now][t] += num[tt][0];
    num[now][t ^ 1] += num[tt][1];
  }
  ans += (sum << w);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans += a[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 0; i <= 20; i++) dfs(1, 0, i);
  printf("%I64d\n", ans);
  return 0;
}

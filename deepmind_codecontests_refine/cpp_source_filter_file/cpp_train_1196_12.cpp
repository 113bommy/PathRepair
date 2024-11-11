#include <bits/stdc++.h>
using namespace std;
const int maxn = 100101;
int pre[maxn], ind[maxn], cnt[maxn], f[maxn];
vector<int> g[maxn], q;
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    g[l].push_back(r);
    g[r].push_back(l);
    ind[l]++;
    ind[r]++;
  }
  q.push_back(1);
  for (int i = 0; i < q.size(); ++i) {
    int now = q[i];
    for (int j = 0; j < g[now].size(); ++j)
      if (g[now][j] != pre[now]) {
        pre[g[now][j]] = now;
        q.push_back(g[now][j]);
      }
  }
  bool flag = 1;
  for (int i = (int)q.size() - 1; i >= 0; --i) {
    int now = q[i];
    int k = cnt[now] + (ind[now] > 3);
    if (k) f[pre[now]]++;
    if (ind[now] > 2) cnt[now]++;
    cnt[pre[now]] += cnt[now];
  }
  int sum = cnt[1];
  for (int i = 1; i < q.size(); ++i) {
    int now = q[i];
    for (int j = 0; j < g[now].size(); ++j)
      if (g[now][j] != pre[now]) {
        int k = sum - cnt[g[now][j]] - (ind[now] > 2) + (ind[now] > 3);
        if (k) f[g[now][j]]++;
      }
  }
  for (int i = 1; i <= n; ++i)
    if (f[i] > 2) flag = 0;
  if (flag)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}

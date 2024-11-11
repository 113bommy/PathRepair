#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int a[N], l[305], r[305];
vector<int> add[N], sub[N];
int ansc[305];
void change(int l, int r, int v) {
  for (int i = l; i <= r; i++) a[i] += v;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &l[i], &r[i]);
      sub[l[i]].push_back(i);
      add[r[i] + 1].push_back(i);
    }
    int maxi, mini;
    maxi = mini = a[1];
    for (int i = 2; i <= n; i++) maxi = max(maxi, a[i]), mini = min(mini, a[i]);
    int ans = maxi - mini, id;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < add[i].size(); j++) {
        int ind = add[i][j];
        change(l[ind], r[ind], 1);
      }
      for (int j = 0; j < sub[i].size(); j++) {
        int ind = sub[i][j];
        change(l[ind], r[ind], -1);
      }
      if (!sub[i].empty() or !add[i].empty()) {
        maxi = mini = a[1];
        for (int i = 2; i <= n; i++)
          maxi = max(maxi, a[i]), mini = min(mini, a[i]);
        if (ans < maxi - mini) ans = maxi - mini, id = i;
      }
    }
    printf("%d\n", ans);
    int c = 0;
    for (int i = 1; i <= m; i++)
      if (l[i] <= id && id <= r[i]) ansc[c++] = i;
    printf("%d\n", c);
    for (int i = 0; i < c; i++) printf("%d ", ansc[i]);
    printf("\n");
  }
  return 0;
}

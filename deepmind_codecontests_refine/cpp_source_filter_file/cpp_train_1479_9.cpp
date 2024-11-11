#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
bool vis[maxn];
long long val[3][maxn];
long long mii[3];
vector<int> g[maxn];
vector<int> a;
int ans[maxn];
int d[maxn];
void dfs(int now) {
  a.push_back(now);
  vis[now] = 1;
  for (int i = 0; i < g[now].size(); i++) {
    if (vis[g[now][i]]) continue;
    dfs(g[now][i]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int j = 0; j < 3; j++) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &val[j][i]);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int f, t;
    scanf("%d%d", &f, &t);
    g[f].push_back(t);
    g[t].push_back(f);
    d[f]++;
    d[t]++;
    if (d[f] > 2 || d[t] > 2) {
      printf("-1\n");
      return 0;
    }
  }
  vector<int> temp;
  temp.push_back(0);
  temp.push_back(1);
  temp.push_back(2);
  for (int i = 1; i <= n; i++) {
    if (d[i] == 1) {
      dfs(i);
      break;
    }
  }
  long long mi = 1ll << 60;
  for (int _ = 0; _ < 6; _++) {
    long long now = 0;
    for (int i = 0; i < n; i++) {
      now += val[temp[i % 3]][a[i]];
    }
    if (now < mi) {
      mi = now;
      for (int j = 0; j < 3; j++) {
        mii[j] = temp[j];
      }
    }
    next_permutation(temp.begin(), temp.end());
  }
  printf("%lld\n", mi);
  for (int i = 0; i < n; i++) {
    ans[a[i]] = temp[i % 3];
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i] + 1);
  }
  puts("");
  return 0;
}

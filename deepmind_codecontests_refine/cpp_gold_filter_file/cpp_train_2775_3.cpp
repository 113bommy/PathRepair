#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
vector<int> ve[maxn], ans;
int deep[maxn], cnt[maxn];
int n;
struct node {
  int u, dep;
  friend bool operator<(const node &a, const node &b) { return a.dep < b.dep; }
};
priority_queue<node> q;
void dfs(int u, int fa) {
  deep[u] = deep[fa] + 1;
  if (cnt[u] % 2 == 0) {
    q.push({u, deep[u]});
  }
  for (int i = 0; i < cnt[u]; i++) {
    if (ve[u][i] != fa) dfs(ve[u][i], u);
  }
}
bool vis[maxn];
void init() {
  for (int i = 1; i <= n; i++) {
    ve[i].clear();
  }
  memset(cnt, 0, sizeof(cnt));
  ans.clear();
}
int main() {
  while (cin >> n) {
    int x, rt;
    init();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (x) {
        ve[x].push_back(i);
        ve[i].push_back(x);
        cnt[x]++, cnt[i]++;
      } else {
        rt = i;
      }
    }
    if (n % 2 == 0) {
      puts("NO");
      continue;
    }
    dfs(rt, 0);
    x = 0;
    while (!q.empty()) {
      node s = q.top();
      q.pop();
      if (cnt[s.u] % 2 == 1 || vis[s.u] == 1) continue;
      ans.push_back(s.u);
      vis[s.u] = 1;
      x++;
      int si = ve[s.u].size();
      for (int i = 0; i < si; i++) {
        int y = ve[s.u][i];
        if (!vis[y])
          if ((--cnt[y]) % 2 == 0) {
            q.push({y, deep[y]});
          }
      }
    }
    if (x < n)
      puts("NO");
    else {
      puts("YES");
      for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int base[2], p[N], vis[N], n;
bool in[N];
vector<int> ans;
bool dfs(int cur, int step) {
  vis[cur] = step;
  ans.push_back(cur);
  if (!vis[p[cur]]) return dfs(p[cur], step + 1);
  int t = step + 1 - vis[p[cur]];
  return base[0] == base[1] || t == 1 || t % 2 == 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    in[p[i]] = 1;
    if (i == p[i]) base[0] = base[1] = i;
  }
  if (base[0] == 0) {
    for (int i = 1; i <= n; i++) {
      if (i == p[p[i]]) {
        base[0] = i;
        base[1] = p[i];
        break;
      }
    }
  }
  if (base[0] == 0)
    puts("NO");
  else {
    vis[base[0]] = vis[base[1]] = 1;
    for (int i = 1; i <= n; i++) {
      if (!in[i]) {
        if (!dfs(i, 1)) {
          puts("NO");
          return 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        if (!dfs(i, 1)) {
          puts("NO");
          return 0;
        }
      }
    }
    puts("YES");
    if (base[0] != base[1]) printf("%d %d\n", base[0], base[1]);
    int len = ans.size();
    for (int i = 0; i < len; i++) printf("%d %d\n", base[i & 1], ans[i]);
    puts("");
  }
}

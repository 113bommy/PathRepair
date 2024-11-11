#include <bits/stdc++.h>
using namespace std;
int n, vis[26][200005], pre[26][200005], ans[200005];
char s[200005];
inline int find(int id, int x) {
  return x == pre[id][x] ? x : pre[id][x] = find(id, pre[id][x]);
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j <= n; ++j) pre[i][j] = j;
  }
  int mx = 1;
  for (int i = 1; i <= n; ++i) {
    int id = s[i] - 'a';
    ans[i] = find(id, 0) + 1;
    mx = max(mx, ans[i]);
    for (int j = 0; j < id; ++j) {
      if (!vis[j][ans[i]]) {
        vis[j][ans[i]] = 1;
        pre[j][ans[i] - 1] = ans[i];
      }
    }
  }
  if (mx == 2) {
    printf("YES\n");
    for (int i = 1; i <= n; ++i) printf("%d", ans[i] - 1);
  } else
    printf("NO");
  return 0;
}

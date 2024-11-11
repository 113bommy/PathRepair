#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, i, a, ch[N * 30][2], k, p, u, d[N * 30], j;
long long ans;
int dfs2(int a, int b) {
  bool flag = true;
  int s = 1 << 30;
  if (ch[a][0] == 0 && ch[a][1] == 0) return 0;
  if (ch[a][0] != 0 && ch[b][0] != 0) {
    s = min(s, dfs2(ch[a][0], ch[b][0]));
    flag = false;
  }
  if (ch[a][1] != 0 && ch[b][1] != 0) {
    s = min(s, dfs2(ch[a][1], ch[b][1]));
    flag = false;
  }
  if (flag) {
    if (ch[a][0] != 0 && ch[b][1] != 0)
      s = min(s, dfs2(ch[a][0], ch[b][1]) + (1 << d[a]));
    if (ch[a][1] != 0 && ch[b][0] != 0)
      s = min(s, dfs2(ch[a][1], ch[b][0]) + (1 << d[a]));
  }
  return s;
}
void dfs(int p) {
  if (ch[p][1] == 0 && ch[p][0] == 0) return;
  if (ch[p][0] == 0)
    dfs(ch[p][1]);
  else if (ch[p][1] == 0)
    dfs(ch[p][0]);
  else {
    ans += dfs2(ch[p][0], ch[p][1]) + (1 << d[p]);
    dfs(ch[p][0]);
    dfs(ch[p][1]);
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    p = 0;
    for (j = 29; j >= 0; j--) {
      int t = (a >> j) & 1;
      if (ch[p][t] == 0) {
        ch[p][t] = ++u;
        d[u] = j - 1;
      }
      p = ch[p][t];
    }
  }
  dfs(0);
  cout << ans;
}

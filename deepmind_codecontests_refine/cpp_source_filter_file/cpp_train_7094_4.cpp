#include <bits/stdc++.h>
using namespace std;
int T, n, st[100010], t, cnt = 0, as[100010], b[100010], col[100010],
                         ans[3][100010];
pair<int, int> vec[100010];
bool vis[100010], op[100010];
void qry() {
  for (int i = 1; i <= cnt; i++) op[i] = false;
  while (true) {
    t = 0;
    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= cnt; i++) {
      if (op[i]) continue;
      if (!vis[vec[i].first] && !vis[vec[i].second])
        op[i] = true, vis[vec[i].first] = vis[vec[i].second] = true,
        st[++t] = i;
    }
    if (!t) break;
    printf("Q %d ", t);
    for (int i = 1; i <= t; i++)
      printf("%d %d ", vec[st[i]].first, vec[st[i]].second);
    puts("");
    fflush(stdout);
    for (int i = 1; i <= t; i++) scanf("%1d", &as[st[i]]);
  }
  cnt = 0;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) vec[++cnt] = make_pair(i, i + 1);
  qry();
  for (int i = 1, lst = 0; i < n; i++) {
    b[i] = as[i];
    if (b[i]) continue;
    if (lst) vec[++cnt] = make_pair(lst, i + 1);
    lst = i;
  }
  qry();
  col[1] = 0;
  for (int i = 1, lst = 0; i < n; i++) {
    if (b[i]) {
      col[i + 1] = col[i];
      continue;
    }
    if (lst) {
      if (as[++cnt])
        col[i + 1] = col[lst];
      else
        col[i + 1] = 3 ^ col[lst] ^ col[i];
    } else
      col[i + 1] = 1;
    lst = i;
  }
  cnt = 0;
  ans[0][0] = ans[1][0] = ans[2][0] = 0;
  for (int i = 1; i <= n; i++) ans[col[i]][++ans[col[i]][0]] = i;
  printf("%d %d %d\n", ans[0][0], ans[1][0], ans[2][0]);
  for (int k = 0; k < 3; k++) {
    for (int i = 1; i <= ans[k][0]; i++) printf("%d ", ans[k][i]);
    puts("");
  }
  fflush(stdout);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
}

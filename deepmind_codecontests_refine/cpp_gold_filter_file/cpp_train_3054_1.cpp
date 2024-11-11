#include <bits/stdc++.h>
using namespace std;
int n, m, P;
int dis[605][605];
int a[605][605], k;
int info[605], to[605 * 605 * 2], Prev[605 * 605 * 2], cnt_e;
int in[605], ot[605];
int s[605], t[605];
int Q[605], L, R;
void Node(int u, int v) {
  cnt_e++;
  Prev[cnt_e] = info[u], info[u] = cnt_e, to[cnt_e] = v;
}
int det() {
  int ret = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++)
      while (a[j][i]) {
        int t = a[i][i] / a[j][i];
        for (int p = i; p <= k; p++) {
          a[i][p] = (a[i][p] - 1ll * t * a[j][p]) % P;
          swap(a[i][p], a[j][p]);
        }
        ret = -ret;
      }
    if (!a[i][i]) return 0;
    ret = (1ll * ret * a[i][i]) % P;
  }
  return (ret + P) % P;
}
int main() {
  scanf("%d%d%d", &n, &m, &P);
  for (int u, v, i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    Node(u, v);
    in[v]++;
    ot[u]++;
    dis[u][v]++;
  }
  for (int i = 1; i <= n; i++) {
    dis[i][i] = 1;
    if (!in[i]) s[++s[0]] = i, Q[R++] = i;
    if (!ot[i]) t[++t[0]] = i;
  }
  for (int now; L < R;) {
    now = Q[L++];
    for (int i = info[now]; i; i = Prev[i]) {
      in[to[i]]--;
      if (!in[to[i]]) Q[R++] = to[i];
      for (int j = 1; j <= n; j++)
        if (now != j) dis[j][to[i]] = (dis[j][to[i]] + dis[j][now]) % P;
    }
  }
  k = s[0];
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++) a[i][j] = dis[s[i]][t[j]];
  printf("%d", det());
}

#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6 + 100;
int pa[Max << 1], son[Max << 1][27];
int deep[Max << 1], sum[Max << 1], tp[Max << 1], S[Max << 1], cnt, root, last;
char str[Max << 1];
inline int Newnode(int _deep) {
  deep[++cnt] = _deep;
  return cnt;
}
inline void SAM(int alp) {
  int np = Newnode(deep[last] + 1);
  int u = last;
  S[np] = 1;
  memset(son[np], 0, sizeof(son[np]));
  while (u && !son[u][alp]) son[u][alp] = np, u = pa[u];
  if (!u)
    pa[np] = root;
  else {
    int v = son[u][alp];
    if (deep[v] == deep[u] + 1)
      pa[np] = v;
    else {
      int nv = Newnode(deep[u] + 1);
      memcpy(son[nv], son[v], sizeof(son[v]));
      pa[nv] = pa[v], pa[v] = pa[np] = nv;
      while (u && son[u][alp] == v) son[u][alp] = nv, u = pa[u];
    }
  }
  last = np;
}
inline void toposort() {
  for (int i = 1; i <= deep[last]; i++) sum[i] = 0;
  for (int i = 1; i <= cnt; i++) sum[deep[i]]++;
  for (int i = 1; i <= deep[last]; i++) sum[i] += sum[i - 1];
  for (int i = 1; i <= cnt; i++) tp[sum[deep[i]]--] = i;
  for (int i = cnt; i >= 1; i--) S[pa[tp[i]]] += S[tp[i]];
}
inline void pre() { root = last = Newnode(0); }
int flag[Max << 1], N, Q;
inline void Query() {
  int now = root, L = 0, ans = 0;
  for (int i = 1; i <= N + N; i++) {
    int c = str[i] - 'a';
    if (son[now][c])
      L++, now = son[now][c];
    else {
      while (now && !son[now][c]) now = pa[now];
      if (!now)
        now = root, L = 0;
      else
        L = deep[now] + 1, now = son[now][c];
    }
    if (i > N && L >= N) {
      int tmp = now;
      while (tmp && !(N >= deep[pa[tmp]] + 1 && N <= deep[tmp])) tmp = pa[tmp];
      if (!tmp) tmp = root;
      if (flag[tmp] != Q + 1) ans += S[tmp], flag[tmp] = Q + 1;
    }
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%s", str);
  pre();
  int len = strlen(str);
  for (int a = 0; a < len; a++) SAM(str[a] - 'a');
  toposort();
  scanf("%d", &Q);
  while (Q--) {
    scanf("%s", str + 1);
    N = strlen(str + 1);
    for (int b = 1; b <= N; b++) str[b + N] = str[b];
    Query();
  }
  return 0;
}

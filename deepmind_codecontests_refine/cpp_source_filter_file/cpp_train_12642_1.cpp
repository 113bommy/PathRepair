#include <bits/stdc++.h>
using namespace std;
typedef int arr[10010];
arr ma, ps, cx, fa, bt, tp, cd;
int cur, cnt, lst, now, q, ne, od, ans = 10010, trs[10010][26];
char ch;
void ext(int x) {
  ma[cur = ++cnt] = ma[lst] + 1, ++ps[cur];
  for (now = lst; now && !trs[now][x]; now = fa[now]) trs[now][x] = cur;
  od = trs[now][x];
  if (!now)
    fa[cur] = 1;
  else if (ma[od] == ma[now] + 1)
    fa[cur] = od;
  else {
    ma[ne = ++cnt] = ma[now] + 1;
    memcpy(trs[ne], trs[od], sizeof(trs[od]));
    fa[ne] = fa[od];
    fa[od] = fa[cur] = ne;
    for (; now && trs[now][x] == od; now = fa[now]) trs[now][x] = ne;
  }
  lst = cur;
}
inline void topo() {
  for (int i = 1; i <= cnt; ++i) ++bt[ma[i]];
  for (int i = 1; i <= ma[lst]; ++i) bt[i] += bt[i - 1];
  for (int i = 1; i <= cnt; ++i) tp[bt[ma[i]]--] = i;
}
int main() {
  cnt = lst = 1;
  for (ch = getchar(); ch != '\n'; ch = getchar()) {
    ext(ch - 'a');
  }
  topo();
  for (int i = cnt; i; --i) ps[fa[tp[i]]] += ps[tp[i]];
  for (int i = 0; i < 26; ++i) trs[0][i] = 1;
  ma[0] = -1;
  for (now = 1, ch = getchar(); ch != '\n'; ch = getchar()) {
    for (ch -= 'a'; !trs[now][ch]; now = fa[now])
      ;
    ++cx[now = trs[now][ch]];
  }
  for (int i = cnt; i; --i) cx[fa[tp[i]]] += cx[tp[i]];
  for (int i = 2; i ^ cnt; ++i)
    if (cx[i] == 1 && ps[i] == 1) ans = min(ans, ma[fa[i]] + 1);
  printf("%d\n", ans == 10010 ? -1 : ans);
}

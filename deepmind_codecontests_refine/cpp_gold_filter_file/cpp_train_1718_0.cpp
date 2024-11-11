#include <bits/stdc++.h>
using namespace std;
const int _ = 100000 + 7;
const int inf = 0x3f3f3f3f;
int n, a[_], ans[_], q[_], _now, num[2], st[2][_], tot[2], nxt[_][2];
bool vis[_];
char s[_];
int _find(int x, int t) {
  return (nxt[x][t] == x || !nxt[x][t]) ? nxt[x][t]
                                        : nxt[x][t] = _find(nxt[x][t], t);
}
void init() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int cnt[2] = {0, 0};
  for (int i = 1; i <= n; i++) {
    a[i] = s[i] == 'L' ? 0 : 1;
    num[a[i]]++;
    cnt[a[i]]++;
    if (!cnt[!a[i]])
      st[a[i]][++tot[a[i]]] = i;
    else
      cnt[!a[i]]--;
  }
  ans[0] = tot[0] + tot[1] - 1;
  for (int i = n; i >= 1; i--) {
    nxt[i][a[i]] = i;
    nxt[i][!a[i]] = nxt[i + 1][!a[i]];
  }
}
void run(int ty) {
  if (!tot[ty]) return;
  int x = st[ty][tot[ty]--], lst = 0, llst = 0;
  while (1) {
    ans[++_now] = x;
    vis[x] = 1;
    llst = lst;
    lst = x;
    x = _find(x, !a[x]);
    if (!x) {
      x = lst;
      if (_now != n && tot[!a[x]] == 0) {
        vis[x] = 0;
        _now--;
        x = llst;
      } else
        nxt[llst][a[llst]] = nxt[llst + 1][a[llst]];
      nxt[x][a[x]] = nxt[x + 1][a[x]];
      break;
    }
    if (llst) nxt[llst][a[llst]] = nxt[llst + 1][a[llst]];
  }
  if (_now == n) return;
  run(!a[x]);
}
int main() {
  init();
  if (num[0] >= num[1]) run(0);
  if (num[1] > num[0] || _now != n) run(1);
  printf("%d\n", ans[0]);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}

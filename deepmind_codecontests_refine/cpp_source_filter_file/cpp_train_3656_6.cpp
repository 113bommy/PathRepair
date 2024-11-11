#include <bits/stdc++.h>
using namespace std;
int visit[510][5100];
int d, s;
int qd[500010], qs[500010];
int digit[500010], last[500010];
int res[1000000];
void bfs() {
  qd[1] = 0;
  qs[1] = 0;
  visit[0][0] = 1;
  int h = 0, t = 1, nowd, nows, newd, news;
  for (; h < t;) {
    nowd = qd[++h];
    nows = qs[h];
    for (int i = 0; i < 10; i++) {
      newd = nowd * 10 + i;
      newd %= d;
      news = nows + i;
      if (news > s) continue;
      if (visit[newd][news]) continue;
      visit[newd][news] = ++t;
      digit[t] = i;
      last[t] = h;
      qd[t] = newd;
      qs[t] = news;
    }
  }
}
int main() {
  scanf("%d%d", &d, &s);
  bfs();
  int p = visit[0][s], cnt = 0;
  if (p == 0)
    printf("-1\n");
  else {
    for (; p != 1; p = last[p]) res[++cnt] = digit[p];
    for (int i = cnt; i; i--) printf("%d", res[i]);
    printf("\n");
  }
  return 0;
}

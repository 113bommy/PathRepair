#include <bits/stdc++.h>
using namespace std;
int ver[5100];
int l[10100][3];
bool vis[10500];
int par[10500];
int c[10500];
void Search(int v) {
  int cur;
  vis[v] = true;
  int temp = ver[v];
  while (temp != 0) {
    cur = l[temp][0];
    if (!vis[cur]) {
      par[cur] = v;
      c[cur] = l[temp][2];
      Search(cur);
    }
    temp = l[temp][1];
  }
}
int days[5050][5050];
int gorod[5050];
int res[5050];
int a[1050];
int main() {
  memset(ver, 0, sizeof(ver));
  memset(vis, false, sizeof(vis));
  memset(days, 0, sizeof(days));
  int n, cnt;
  int tmp;
  int i, j, w;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    gorod[i] = i;
  }
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
      if (a[i] > a[j]) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        tmp = gorod[i];
        gorod[i] = gorod[j];
        gorod[j] = tmp;
      }
  for (cnt = 1; cnt < n; cnt++) {
    scanf("%d%d%d", &i, &j, &w);
    l[cnt * 2 - 1][0] = j;
    l[cnt * 2 - 1][1] = ver[i];
    l[cnt * 2 - 1][2] = w;
    ver[i] = cnt * 2 - 1;
    l[cnt * 2][2] = w;
    l[cnt * 2][0] = i;
    l[cnt * 2][1] = ver[j];
    ver[j] = cnt * 2;
  }
  int cur, day;
  Search(1);
  for (i = 1; i <= n; i++) {
    cur = gorod[i];
    day = 1;
    while (cur != 1) {
      if (days[cur][day] < c[cur]) {
        days[cur][day]++;
        cur = par[cur];
      }
      day++;
    }
    res[gorod[i]] = day - 1;
  }
  for (i = 1; i <= n; i++) printf("%d ", res[i]);
  return 0;
}

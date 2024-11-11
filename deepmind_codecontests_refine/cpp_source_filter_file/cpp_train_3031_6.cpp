#include <bits/stdc++.h>
using namespace std;
int plc[4], dis1[4], dis2[4], ans;
bool vis[10000007];
struct node {
  int p[4], r[4], t[4], l[4];
  int hash() {
    int h = 0, w = 233;
    for (int i = 1; i <= 3; i++) {
      w = 1ll * w * w % 10000007;
      h = (h + 1ll * w * p[i] % 10000007 +
           1ll * w * (r[i] + 1) * (t[i] + 5) * l[i] * l[i]) %
          10000007;
    }
    return h;
  }
} st;
queue<node> q;
void bfs() {
  node x;
  while (!q.empty()) {
    st = q.front();
    q.pop();
    for (int i = 1; i <= 3; i++) ans = max(ans, st.p[i]);
    for (int i = 1; i <= 3; i++) {
      int f = 0;
      for (int j = 1; j <= 3; j++)
        if (j != i && st.l[j] == i) f = 1;
      if (f) continue;
      if (!st.r[i] && st.l[i] == i) {
        for (int j = max(1, st.p[i] - dis1[i]); j <= st.p[i] + dis1[i]; j++) {
          int flg = 1;
          for (int k = 1; k <= 3; k++)
            if (j == st.p[k]) flg = 0;
          if (!flg) continue;
          x = st;
          x.p[i] = j;
          x.r[i] = 1;
          if (!vis[x.hash()]) vis[x.hash()] = 1, q.push(x);
        }
      }
      if (!st.t[i] && st.l[i] != i) {
        for (int j = max(1, st.p[i] - dis2[i]); j <= st.p[i] + dis2[i]; j++) {
          int flg = 1;
          for (int k = 1; k <= 3; k++)
            if (j == st.p[k]) flg = 0;
          if (!flg) continue;
          x = st;
          x.p[st.l[i]] = x.p[st.l[st.l[i]]] = j;
          x.t[i] = 1;
          x.l[i] = i;
          if (!vis[x.hash()]) vis[x.hash()] = 1, q.push(x);
        }
      }
      if (!st.t[i] && st.l[i] == i) {
        for (int j = 1; j <= 3; j++) {
          if (((st.p[j] - st.p[i]) > 0 ? (st.p[j] - st.p[i])
                                       : -(st.p[j] - st.p[i])) == 1) {
            int flg = 1;
            for (int k = 1; k <= 3; k++)
              if (j != k && j == st.l[k]) flg = 0;
            if (!flg) continue;
            x = st;
            x.p[j] = x.p[st.l[j]] = x.p[i];
            x.l[i] = j;
            if (!vis[x.hash()]) vis[x.hash()] = 1, q.push(x);
          }
        }
      }
    }
  }
}
int main() {
  for (int i = 1; i <= 3; i++) scanf("%d%d%d", &plc[i], &dis1[i], &dis2[i]);
  st.p[1] = plc[1];
  st.p[2] = plc[2];
  st.p[3] = plc[3];
  st.l[1] = 1;
  st.l[2] = 2;
  st.l[3] = 3;
  q.push(st);
  vis[st.hash()] = 1;
  bfs();
  printf("%d\n", ans);
}

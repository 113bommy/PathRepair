#include <bits/stdc++.h>
using namespace std;
int nd[100005];
int n, m, nq;
vector<int> g[100005];
vector<int> w[100005];
int tq[100005];
int aq[100005];
int bq[100005];
int rs[100005];
int nn;
int b[1024][1024];
bool inv[1024];
int q[1024];
int r;
void dfs(int x) {
  int c;
  if (tq[x] == 1 || tq[x] == 2) {
    int i = aq[x], j = bq[x], t = 2 - tq[x];
    c = b[i][j];
    if (!inv[i]) {
      if (c != t) {
        b[i][j] = t;
        if (t)
          q[i]++, r++;
        else
          q[i]--, r--;
      }
    } else {
      if (c == t) {
        b[i][j] = 1 - c;
        if (t)
          q[i]--, r++;
        else
          q[i]++, r--;
      }
    }
  } else if (tq[x] == 3) {
    int k = aq[x];
    int s0 = q[k], s1 = m - q[k];
    if (inv[k]) swap(s0, s1);
    inv[k] = !inv[k];
    r += s1 - s0;
  }
  for (int i = 0, to = w[x].size(); i < to; ++i) rs[w[x][i]] = r;
  for (int i = 0, to = g[x].size(); i < to; ++i) dfs(g[x][i]);
  if (tq[x] == 1 || tq[x] == 2) {
    int i = aq[x], j = bq[x], t = 2 - tq[x];
    swap(c, t);
    if (inv[i]) c = 1 - c, t = 1 - t;
    if (!inv[i]) {
      if (c != t) {
        b[i][j] = t;
        if (t)
          q[i]++, r++;
        else
          q[i]--, r--;
      }
    } else {
      if (c == t) {
        b[i][j] = 1 - c;
        if (t)
          q[i]--, r++;
        else
          q[i]++, r--;
      }
    }
  } else if (tq[x] == 3) {
    int k = aq[x];
    int s0 = q[k], s1 = m - q[k];
    if (inv[k]) swap(s0, s1);
    inv[k] = !inv[k];
    r += s1 - s0;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &nq);
  for (int i = 1, to = nq + 1; i < to; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 4) {
      int x;
      scanf("%d", &x);
      nd[i] = nd[x];
    } else {
      nd[i] = i;
      tq[i] = t;
      if (t <= 2)
        scanf("%d%d", aq + i, bq + i), aq[i]--, bq[i]--;
      else
        scanf("%d", aq + i), aq[i]--;
      g[nd[i - 1]].push_back(nd[i]);
    }
    w[nd[i]].push_back(i);
  }
  dfs(0);
  for (int i = 1, to = nq + 1; i < to; ++i) printf("%d\n", rs[i]);
  return 0;
}

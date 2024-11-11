#include <bits/stdc++.h>
using namespace std;
inline void add(int &x, int y) {
  ((x += y) >= 1000000007) ? x -= 1000000007 : 0;
}
struct Edge {
  int t, next;
  bool v;
  Edge() {}
  Edge(int a, bool b, int c) : t(a), v(b), next(c) {}
};
Edge e[200005];
int head[100005], d[100005], tot;
bool vis1[100005], vis2[100005], tag[100005];
vector<int> bel[100005];
bool odd[100005];
int ans[2];
inline void addEdge(int x, int y, bool v) {
  e[++tot] = Edge(y, v, head[x]);
  head[x] = tot;
  e[++tot] = Edge(x, v, head[y]);
  head[y] = tot;
  d[x]++;
  d[y]++;
}
inline void merge(int *p) {
  int sum[2] = {0, 0};
  for (int t1 = 0; t1 < 2; t1++)
    for (int t2 = 0; t2 < 2; t2++)
      add(sum[t1 ^ t2], (long long)ans[t1] * p[t2] % 1000000007);
  ans[0] = sum[0];
  ans[1] = sum[1];
}
int q[100005];
bool val[100005];
void dp_chain(int n) {
  int f[2][2][2];
  int cur = 0;
  memset(f[cur], 0, sizeof(f[cur]));
  f[cur][0][0] = 1;
  if (odd[q[1]]) f[cur][0][1] = 1;
  for (int i = 1; i < n; i++) {
    int x = q[i];
    cur ^= 1;
    memset(f[cur], 0, sizeof(f[cur]));
    for (int t1 = 0; t1 < 2; t1++)
      for (int t2 = 0; t2 < 2; t2++)
        if (f[cur ^ 1][t1][t2]) {
          for (int t3 = 0; t3 < 2; t3++)
            add(f[cur][t1 ^ (t2 | t3)][t3 ^ val[i]], f[cur ^ 1][t1][t2]);
        }
  }
  int sum[2] = {0, 0};
  if (odd[q[n]]) {
    for (int t1 = 0; t1 < 2; t1++)
      for (int t2 = 0; t2 < 2; t2++)
        if (f[cur][t1][t2]) {
          for (int t3 = 0; t3 < 2; t3++)
            add(sum[t1 ^ (t2 | t3)], f[cur][t1][t2]);
        }
  } else {
    for (int t1 = 0; t1 < 2; t1++)
      for (int t2 = 0; t2 < 2; t2++)
        if (f[cur][t1][t2]) add(sum[t1 ^ t2], f[cur][t1][t2]);
  }
  merge(sum);
}
void dp_cir(int n) {
  int f[2][2][2][2];
  int cur = 0;
  memset(f[cur], 0, sizeof(f[cur]));
  f[cur][0][0][0] = f[cur][0][1][1] = 1;
  for (int i = 1; i < n; i++) {
    int x = q[i];
    cur ^= 1;
    memset(f[cur], 0, sizeof(f[cur]));
    for (int t1 = 0; t1 < 2; t1++)
      for (int t2 = 0; t2 < 2; t2++)
        for (int t3 = 0; t3 < 2; t3++)
          if (f[cur ^ 1][t1][t2][t3]) {
            for (int t4 = 0; t4 < 2; t4++)
              add(f[cur][t1 ^ (t2 | t4)][t4 ^ val[i]][t3],
                  f[cur ^ 1][t1][t2][t3]);
          }
  }
  int sum[2] = {0, 0};
  for (int t1 = 0; t1 < 2; t1++)
    for (int t2 = 0; t2 < 2; t2++)
      for (int t3 = 0; t3 < 2; t3++)
        if (f[cur][t1][t2][t3])
          add(sum[t1 ^ (t2 | (t3 ^ val[n]))], f[cur][t1][t2][t3]);
  merge(sum);
}
int find_path(int s) {
  int cnt = 0, x = s;
  do {
    q[++cnt] = x;
    vis1[x] = 1;
    int u = 0;
    for (int i = head[x]; i; i = e[i].next)
      if (!vis2[(i + 1) >> 1]) {
        u = e[i].t;
        vis2[(i + 1) >> 1] = 1;
        val[cnt] = e[i].v;
        break;
      }
    x = u;
  } while (x && x != s);
  return cnt;
}
vector<int> vt[100005];
int main() {
  ans[0] = 1;
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    vt[i].resize(x);
    for (int j = 0; j < x; j++) {
      scanf("%d", &vt[i][j]);
      bel[abs(vt[i][j])].push_back(i);
      tag[abs(vt[i][j])] ^= (vt[i][j] < 0);
    }
  }
  for (int i = 1; i <= m; i++)
    if (!bel[i].size())
      ans[0] = ans[0] * 2LL % 1000000007;
    else if (bel[i].size() == 1)
      odd[bel[i][0]] = 1;
    else if (bel[i][0] != bel[i][1])
      addEdge(bel[i][0], bel[i][1], tag[i]);
  for (int i = 1; i <= n; i++)
    if (!d[i]) {
      int sum[2] = {0, 0};
      if (vt[i].size() == 1)
        sum[0] = sum[1] = 1;
      else if (abs(vt[i][0]) != abs(vt[i][1]))
        sum[0] = 1, sum[1] = 3;
      else if ((vt[i][0] > 0) ^ (vt[i][1] > 0))
        sum[0] = 2;
      else
        sum[0] = sum[1] = 1;
      merge(sum);
    } else if (d[i] == 1 && !vis1[i]) {
      int cnt = find_path(i);
      dp_chain(cnt);
    }
  for (int i = 1; i <= n; i++)
    if (d[i] == 2 && !vis1[i]) {
      int cnt = find_path(i);
      dp_cir(cnt);
    }
  printf("%d\n", ans[1]);
  return 0;
}

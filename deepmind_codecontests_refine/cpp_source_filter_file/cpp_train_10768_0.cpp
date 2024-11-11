#include <bits/stdc++.h>
using namespace std;
int gap[11000], dis[11000], pre[11000], cur[11000];
int size, n, head[11000];
struct Node {
  int c, v, next;
  Node() {}
  Node(int _v, int _c, int _next) : v(_v), c(_c), next(_next) {}
} E[110000];
int sap(int s, int t) {
  memset(dis, 0, sizeof(dis));
  memset(gap, 0, sizeof(gap));
  for (int i = 1; i <= n; i++) cur[i] = head[i];
  int u = pre[s] = s, maxflow = 0, aug = -1;
  gap[0] = n;
  while (dis[s] < n) {
  loop:
    for (int &i = cur[u]; i != -1; i = E[i].next) {
      int v = E[i].v;
      if (E[i].c && dis[u] == dis[v] + 1) {
        if (aug == -1 || aug > E[i].c) aug = E[i].c;
        pre[v] = u;
        u = v;
        if (v == t) {
          maxflow += aug;
          for (u = pre[u]; v != s; v = u, u = pre[u]) {
            E[cur[u]].c -= aug;
            E[cur[u] ^ 1].c += aug;
          }
          aug = -1;
        }
        goto loop;
      }
    }
    int mindis = n;
    for (int i = head[u]; i != -1; i = E[i].next) {
      int v = E[i].v;
      if (E[i].c && mindis > dis[v]) {
        cur[u] = i;
        mindis = dis[v];
      }
    }
    if ((--gap[dis[u]]) == 0) break;
    gap[dis[u] = mindis + 1]++;
    u = pre[u];
  }
  return maxflow;
}
void add(int u, int v, int c, int cc = 0) {
  E[size] = Node(v, c, head[u]);
  head[u] = size++;
  E[size] = Node(u, cc, head[v]);
  head[v] = size++;
}
void init() {
  memset(head, -1, sizeof(head));
  size = 0;
}
int nn, mm;
int xi[55][3], L[55], R[55];
int res[110][3];
void read() {
  cin >> nn >> mm;
  for (int i = 0; i < nn; i++)
    for (int f = 0; f < 3; f++) scanf("%d", &xi[i][f]);
  for (int i = 0; i < nn; i++) scanf("%d%d", L + i, R + i);
  for (int i = 0; i < mm; i++) {
    for (int f = 0; f < 3; f++) scanf("%d", &res[i][f]);
    res[i][0]--;
    res[i][1]--;
  }
}
int getid(int a, int b) { return a * 205 + 1 + (b + 101); }
int maxx = 200005;
int cal(int a, int b) { return xi[a][0] * b * b + xi[a][1] * b + xi[a][2]; }
int fun() {
  init();
  n = 10500;
  int s = n - 1, t = n;
  for (int i = 0; i < nn; i++) {
    add(s, getid(i, L[i] - 1), 0x3f3f3f3f);
    add(getid(i, R[i]), t, 0x3f3f3f3f);
    for (int f = L[i] - 1; f < R[i]; f++) {
      add(getid(i, f), getid(i, f + 1), maxx - cal(i, f + 1));
    }
  }
  for (int i = 0; i < mm; i++) {
    int u = res[i][0], v = res[i][1], d = res[i][2];
    for (int f = L[u]; f <= R[u]; f++) {
      int oth = f - d;
      if (oth <= R[v] && oth >= L[v]) {
        add(getid(u, f), getid(v, oth), 0x3f3f3f3f);
      }
    }
  }
  int ans = sap(s, t);
  return maxx * nn - ans;
}
int main() {
  read();
  cout << fun() << endl;
  return 0;
}

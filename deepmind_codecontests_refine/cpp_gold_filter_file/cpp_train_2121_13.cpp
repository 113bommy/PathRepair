#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)3e5 + 10, MOD = (int)1e9 + 7;
struct Graph {
  int id, next, f, dis, tar;
  bool vis;
} g[MAXN * 2];
int n, st[MAXN], d[MAXN], Tohka;
void Add(int tot, int first, int second) {
  g[tot].id = second, g[tot].next = st[first], st[first] = tot;
}
void Plus(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int Get(int e) {
  for (int i = st[g[e].id]; i != -1; i = g[i].next)
    if ((i ^ 1) != e) return i;
  return -1;
}
void DFS(int first) {
  if (g[first].dis) return;
  if (d[g[first].id] != 2) {
    g[first].dis = 1, g[first].tar = first;
    return;
  }
  int i = Get(first);
  DFS(i), g[first].dis = g[i].dis + 1, g[first].tar = g[i].tar;
}
void Get(int &a, int &b, int first) {
  int v = g[first].id;
  for (int i = st[v]; i != -1; i = g[i].next)
    if ((i ^ 1) != first) ((!a) ? (a) : (b)) = i;
  if (d[g[g[a].tar].id] == 1) swap(a, b);
  if (d[g[g[a].tar].id] == 1 && d[g[g[b].tar].id] == 1)
    if (g[a].dis < g[b].dis) swap(a, b);
  if (d[g[g[a].tar].id] == 3 && d[g[g[b].tar].id] == 3)
    if (g[a].dis > g[b].dis) swap(a, b);
}
int Push(int first, int d) {
  for (; d; first = Get(first), --d)
    ;
  return first;
}
void Dp(int first);
int Calc(int a, int b) {
  if (d[g[g[a].tar].id] == 1 && d[g[g[b].tar].id] == 1 && g[a].dis == g[b].dis)
    return 1;
  if (g[a].dis > g[b].dis) swap(a, b);
  if (g[a].dis < g[b].dis && d[g[g[a].tar].id] == 1) {
    int c = Push(b, g[a].dis);
    Dp(c);
    return g[c].f;
  }
  return 0;
}
void Dp(int first) {
  if (g[first].vis) return;
  g[first].vis = 1;
  if (d[g[g[first].tar].id] == 1) {
    g[first].f = (g[first].dis & 1) ? 0 : (g[first].dis / 2);
    return;
  }
  if (d[g[first].id] == 3) {
    int a = 0, b = 0;
    Get(a, b, first);
    if (d[g[g[a].tar].id] == 3 && d[g[g[b].tar].id] == 3) {
      g[first].f = 0;
      return;
    }
    if (g[a].dis == g[b].dis + 1 && d[g[g[a].tar].id] == 1 &&
        d[g[g[b].tar].id] == 1)
      Plus(g[first].f, 1);
    if (g[a].dis > g[b].dis + 1) {
      int c = Push(a, g[b].dis + 1);
      Dp(c);
      Plus(g[first].f, g[c].f);
    }
    if (g[a].dis >= g[b].dis) {
      int c = Push(a, g[b].dis - 1);
      Dp(c);
      Plus(g[first].f, g[c].f);
    }
    return;
  }
  if (g[first].dis > 2) {
    int c = Push(first, 2);
    Dp(c);
    Plus(g[first].f, g[c].f);
  }
  int t[2] = {0, 0};
  Get(t[0], t[1], g[first].tar);
  Dp(t[0]), Dp(t[1]);
  for (int i = 0; i < 2; ++i) {
    if (g[t[i]].dis == g[first].dis && d[g[g[t[i]].tar].id] == 1)
      Plus(g[first].f, g[t[i ^ 1]].f);
    if (g[t[i]].dis == g[first].dis - 2 && d[g[g[t[i]].tar].id] == 1)
      Plus(g[first].f, g[t[i ^ 1]].f);
  }
  int a = t[0], b = t[1];
  if (d[g[a].id] == 3) {
    int c = 0, e = 0;
    Get(c, e, a);
    Dp(c), Dp(e);
    if (g[c].dis == g[first].dis - 1 && d[g[g[c].tar].id] == 1)
      Plus(g[first].f, Calc(b, e));
    if (g[e].dis == g[first].dis - 1 && d[g[g[e].tar].id] == 1)
      Plus(g[first].f, Calc(b, c));
  }
}
int main() {
  scanf("%d", &n);
  if (n == 1) puts("2"), exit(0);
  n *= 2;
  memset(st, -1, sizeof(st));
  for (int i = 1; i < n; ++i) {
    int first, second;
    scanf("%d%d", &first, &second);
    ++d[first], ++d[second];
    Add(i * 2, first, second), Add(i * 2 + 1, second, first);
    if (d[first] > 3 || d[second] > 3) puts("0"), exit(0);
  }
  for (int i = 1; i < n; ++i) DFS(i * 2), DFS(i * 2 + 1);
  for (int i = 2; i < n * 2; ++i) Dp(i);
  for (int i = 1; i <= n; ++i)
    if (d[i] == 1) {
      int a = st[i], b = Push(a, 1);
      if (d[g[g[a].tar].id] == 1)
        Plus(Tohka, 2);
      else {
        int first = 0, second = 0;
        Get(first, second, g[a].tar);
        if (d[g[g[first].tar].id] == 1 && g[a].dis + 1 == g[first].dis)
          Plus(Tohka, g[second].f * 2 % MOD);
        if (d[g[g[second].tar].id] == 1 && g[a].dis + 1 == g[second].dis)
          Plus(Tohka, g[first].f * 2 % MOD);
        if (d[g[first].id] == 3) {
          int c = 0, e = 0;
          Get(c, e, first);
          if (g[c].dis == g[a].dis && d[g[g[c].tar].id] == 1)
            Plus(Tohka, Calc(second, e));
          if (g[e].dis == g[a].dis && d[g[g[e].tar].id] == 1)
            Plus(Tohka, Calc(second, c));
        }
      }
      if (d[g[a].id] == 3) continue;
      for (;;) {
        Plus(Tohka, g[b].f * 2 % MOD);
        if (d[g[b].id] != 2) break;
        b = Get(b);
        if (d[g[b].id] != 2) break;
        b = Get(b);
        a = Get(a);
      }
    }
  cout << Tohka << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

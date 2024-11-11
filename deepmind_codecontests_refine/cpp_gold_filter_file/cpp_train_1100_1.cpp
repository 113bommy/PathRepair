#include <bits/stdc++.h>
using namespace std;
int rint() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && (ch != '-')) ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
void juege() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
struct Edge {
  int son[400005], nxt[400005], lnk[200005], tot;
  void add(int x, int y) {
    tot++;
    son[tot] = y;
    nxt[tot] = lnk[x];
    lnk[x] = tot;
    tot++;
    son[tot] = x;
    nxt[tot] = lnk[y];
    lnk[y] = tot;
  }
} edge;
int R, n, ans;
int ask(int x, int pre) {
  int L = -1;
  for (int j = edge.lnk[x]; j; j = edge.nxt[j])
    if (edge.son[j] != pre) {
      int now = ask(edge.son[j], x);
      if (L == -1) {
        L = now;
        continue;
      }
      if (L != now) {
        if (pre != 0) {
          printf("%d\n", -1);
          exit(0);
        }
        if (R == -1) {
          R = now;
          continue;
        }
        if (R != now) {
          printf("%d\n", -1);
          exit(0);
        }
      }
    }
  if (!pre) {
    int ans = R + L + 2;
    if (!(ans % 2)) {
      while (ans) {
        ans >>= 1;
        if ((ans % 2)) break;
      }
    }
    printf("%d\n", ans);
    exit(0);
  }
  L++;
  return L;
}
int dfs(int x, int pre) {
  int L = -1;
  for (int j = edge.lnk[x]; j; j = edge.nxt[j])
    if (edge.son[j] != pre) {
      int now = dfs(edge.son[j], x);
      if (L == -1) {
        L = now;
        continue;
      }
      if (L != now) ask(x, 0);
    }
  if (pre == 0) ask(x, 0);
  L++;
  return L;
}
int main() {
  n = rint(), R = -1;
  for (int i = (1); i < (n); i++) edge.add(rint(), rint());
  ans = dfs(1, 0);
  printf("%d\n", (ans % 2) ? (ans >> 1) : 0);
  return 0;
}

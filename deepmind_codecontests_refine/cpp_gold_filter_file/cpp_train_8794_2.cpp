#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;
void Assert(bool flag) {
  if (!flag) {
    puts("Fuck You");
    exit(0);
  }
}
int n;
int head[maxn], en[maxn << 1], nxt[maxn << 1], pri[maxn << 1], tot = 1;
inline void add(int u, int v, int w) {
  en[++tot] = v;
  nxt[tot] = head[u];
  head[u] = tot;
  pri[tot] = w;
}
int deg[maxn];
int vec[maxn], vn;
char ans[maxn];
bool vis[maxn], mark[maxn << 1];
int stk[maxn], top;
void dfs(int u) {
  vis[u] = true;
  while (head[u]) {
    int k = head[u];
    head[u] = nxt[k];
    if (!mark[k]) {
      mark[k] = mark[k ^ 1] = true;
      int v = en[k];
      dfs(v);
      stk[++top] = pri[k];
    }
  }
}
void doit() {
  static bool flag;
  flag = false;
  while (top > 0) {
    flag ^= 1;
    Assert(stk[top] == 0 || !ans[stk[top]]);
    ans[stk[top]] = flag ? 'r' : 'b';
    top--;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    y += 200000;
    add(x, y, i);
    add(y, x, i);
    deg[x]++;
    deg[y]++;
  }
  for (int i = 1; i <= 400000; i++) {
    if (deg[i] & 1) {
      vec[vn++] = i;
    }
  }
  Assert(!(vn & 1));
  for (int i = 0; i < vn; i += 2) {
    add(vec[i], vec[i + 1], 0);
    add(vec[i + 1], vec[i], 0);
  }
  for (int i = 0; i < vn; i++) {
    if (!vis[vec[i]]) {
      dfs(vec[i]);
      doit();
    }
  }
  for (int i = 1; i <= 400000; i++) {
    if (!vis[i]) {
      dfs(i);
      doit();
    }
  }
  Assert((int)strlen(ans + 1) == n);
  puts(ans + 1);
  return 0;
}

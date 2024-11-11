#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
inline void write(int ans) {
  if (ans = 0) {
    putchar('0');
    return;
  }
  int t[21], cnt = 0;
  while (ans) {
    t[++cnt] = ans % 10;
    ans /= 10;
  }
  for (int i = cnt; i >= 1; i--) putchar('0' + t[i]);
}
int head[200005], nxt[400005], v[400005], tot = 1, n, m;
bool vis[200005], oc[400005];
int ans[200005][3], cnt = 0;
inline void add(int a, int b) {
  tot++;
  nxt[tot] = head[a];
  head[a] = tot;
  v[tot] = b;
}
void dfs(int pos, int p) {
  int i;
  vis[pos] = 1;
  for (i = head[pos]; i; i = nxt[i]) {
    if (!vis[v[i]]) {
      dfs(v[i], pos);
    }
  }
  vector<int> vec;
  for (i = head[pos]; i; i = nxt[i]) {
    if (oc[i]) {
      continue;
    }
    if (v[i] != p) vec.push_back(i);
  }
  for (i = head[pos]; i; i = nxt[i]) {
    if (oc[i]) {
      continue;
    }
    if (v[i] == p) vec.push_back(i);
  }
  int sz = vec.size();
  for (i = 1; i <= sz / 2; i++) {
    int p1 = vec[i * 2 - 2], p2 = vec[i * 2 - 1];
    oc[p1] = oc[p1 ^ 1] = 1;
    oc[p2] = oc[p2 ^ 1] = 1;
    cnt++;
    ans[cnt][0] = v[p1];
    ans[cnt][1] = pos;
    ans[cnt][2] = v[p2];
  }
}
int main() {
  int i, a, b;
  n = read();
  m = read();
  for (i = 1; i <= m; i++) {
    a = read();
    b = read();
    add(a, b);
    add(b, a);
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  write(cnt);
  putchar('\n');
  for (i = 1; i <= cnt; i++) {
    write(ans[i][0]);
    putchar(' ');
    write(ans[i][1]);
    putchar(' ');
    write(ans[i][2]);
    putchar('\n');
  }
}

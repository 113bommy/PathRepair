#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int inf = INT_MAX;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
struct edge {
  int to, next;
} e[N];
int flag;
int T, n, m, head[N], p[N], h[N], a[N], b[N], t;
int size1[N], size2[N], size[N];
void add(int x, int y) {
  e[++t] = (edge){y, head[x]};
  head[x] = t;
}
void dfs1(int x, int fa) {
  size[x] = p[x];
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    dfs1(y, x);
    size[x] += size[y];
  }
}
void dfs(int x, int fa) {
  size1[x] = a[x], size2[x] = b[x];
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    dfs(y, x);
    size1[x] += size1[y];
    size2[x] += size2[y];
  }
}
int main() {
  read(T);
  while (T--) {
    flag = -1;
    t = 0;
    memset(head, 0, sizeof(head));
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(p[i]);
    for (int i = 1; i <= n; i++) {
      read(h[i]);
    }
    flag = 1;
    for (int i = 1; i <= n - 1; i++) {
      int x, y;
      read(x), read(y);
      add(x, y), add(y, x);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) {
      int tmp = size[i];
      a[i] = (tmp + h[i]) / 2;
      b[i] = (tmp - h[i]) / 2;
      if ((tmp + h[i]) % 2 != 0 || a[i] > tmp || b[i] > tmp || b[i] < 0)
        flag = 0;
    }
    if (flag == 0) {
      puts("NO");
      continue;
    }
    dfs(1, 0);
    flag = 1;
    for (int i = 1; i <= n; i++) {
      if (size1[i] - a[i] > a[i]) {
        flag = 0;
        break;
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}

#include <bits/stdc++.h>
const int MAXN = 2e5 + 5;
struct Edge {
  int to, w, nxt;
} e[MAXN << 1];
int head[MAXN], bk[MAXN], cnt;
inline void add(int u, int v) {
  e[++cnt] = (Edge){v, 0, head[u]};
  head[u] = cnt;
  e[++cnt] = (Edge){u, 0, head[v]};
  head[v] = cnt;
}
std::vector<int> S;
inline void dfs(int v) {
  S.push_back(v);
  for (int &i = head[v]; i; i = e[i].nxt) {
    if (e[i].w) continue;
    e[i].w = 1;
    dfs(e[i].to);
  }
}
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (a > b + 1 || d > c + 1) {
    puts("NO");
    return 0;
  }
  if (a == b + 1) {
    if (c || d) {
      puts("NO");
      return 0;
    }
    puts("YES");
    for (int i = 1; i <= a; ++i) printf("0 1 ");
    puts("0");
    return 0;
  }
  if (d == c + 1) {
    if (a || b) {
      puts("NO");
      return 0;
    }
    puts("YES");
    for (int i = 1; i <= d; ++i) printf("4 3 ");
    puts("4");
    return 0;
  }
  if (b - a == c - d) {
    puts("YES");
    for (int i = 1; i <= a; ++i) printf("0 1 ");
    for (int i = 1; i <= b - a; ++i) printf("2 1 ");
    for (int i = 1; i <= d; ++i) printf("2 3 ");
    puts("");
    return 0;
  }
  if (b - a == c - d + 1) {
    puts("YES");
    printf("1 ");
    for (int i = 1; i <= a; ++i) printf("0 1 ");
    for (int i = 1; i <= c - d; ++i) printf("2 1 ");
    for (int i = 1; i <= d; ++i) printf("2 3 ");
    puts("");
    return 0;
  }
  if (b - a + 1 == c - d) {
    puts("YES");
    for (int i = 1; i <= a; ++i) printf("0 1 ");
    for (int i = 1; i <= b - a; ++i) printf("2 1 ");
    for (int i = 1; i <= d; ++i) printf("2 3 ");
    puts("2");
    return 0;
  }
  puts("NO");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, fh = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * fh;
}
const int maxn = 2e5 + 5;
struct Edge {
  int to, next, num;
} e[maxn << 1];
int head[maxn], tot, de[maxn], n, ans, root;
vector<int> g[maxn];
void connect(int x, int y, int i) {
  e[++tot] = (Edge){y, head[x], i};
  head[x] = tot;
}
void dfs(int now, int from, int last) {
  int pos = 0;
  for (int i = head[now]; i; i = e[i].next) {
    int p = e[i].to;
    if (p == from) continue;
    ++pos;
    if (pos == last) ++pos;
    g[pos].push_back(e[i].num);
    dfs(p, now, e[i].num);
  }
}
int main() {
  n = read();
  for (register int i = 1; i <= n - 1; ++i) {
    int x = read(), y = read();
    connect(x, y, i);
    connect(y, x, i);
    de[x]++;
    de[y]++;
  }
  for (register int i = 1; i <= n; ++i)
    if (ans < de[i]) {
      ans = de[i];
      root = i;
    }
  dfs(root, 0, 0);
  cout << ans << endl;
  for (register int i = 1; i <= ans; ++i) {
    int q = g[i].size();
    printf("%d ", q);
    for (register int j = 0; j <= q - 1; ++j) printf("%d ", g[i][j]);
    puts("");
  }
  return 0;
}

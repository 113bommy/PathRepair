#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100000 + 10;
int pre[Maxn << 1], other[Maxn << 1];
int last[Maxn], path[Maxn << 2];
bool odd[Maxn], v[Maxn];
int l, len, root;
void Add_edge(int p, int q) {
  pre[++l] = last[p];
  last[p] = l;
  other[l] = q;
  pre[++l] = last[q];
  last[q] = l;
  other[l] = p;
}
void Insert(int x) {
  path[len++] = x;
  odd[x] ^= 1;
}
void Dfs(int p, int fa) {
  v[p] = 1;
  Insert(p);
  for (int q = last[p]; q; q = pre[q])
    if (!v[other[q]]) {
      Dfs(other[q], p);
      Insert(p);
    }
  if (odd[p] && p != root) {
    Insert(fa);
    Insert(p);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Add_edge(x, y);
  }
  int flag = 0;
  for (int i = 1; i <= n; ++i) {
    int t;
    scanf("%d", &t);
    if (t) {
      odd[i] = 1;
      root = i;
    }
    flag |= t;
  }
  if (!flag) {
    puts("0");
    return 0;
  }
  Dfs(root, 0);
  for (int i = 1; i <= n; ++i)
    if (odd[i] && i != root) {
      puts("-1");
      return 0;
    }
  if (odd[1]) --len;
  printf("%d\n", len);
  for (int i = 0; i < len; ++i) printf("%d ", path[i]);
  printf("\n");
  return 0;
}

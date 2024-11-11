#include <bits/stdc++.h>
struct node {
  int son[10], fa, fail, ch;
  std::vector<int> war;
} tree[16001];
int n, q[16001];
inline int son(int p, int c) {
  if (tree[p].son[c] == 0) {
    tree[p].son[c] = ++n;
    tree[n].fa = p;
    tree[n].ch = c;
  }
  return tree[p].son[c];
}
int a[802], b[802], L, N;
void read() {
  int A = 0, B = 0;
  char c;
  do c = getchar();
  while (c < 48 || c > 57);
  do a[A++] = c - 48, c = getchar();
  while (c > 47 && c < 58);
  do c = getchar();
  while (c < 48 || c > 57);
  do b[B++] = c - 48, c = getchar();
  while (c > 47 && c < 58);
  scanf("%d", &N);
  std::reverse(a, a + A);
  std::reverse(b, b + B);
  b[0]++;
  for (int i = 0; i < B; i++)
    if (b[i] > 9) {
      b[i + 1]++;
      b[i] -= 10;
    }
  if (b[B]) B++;
  L = B;
}
void BFS() {
  int H = 0, T = 1;
  q[1] = 0;
  while (H < T) {
    int u = q[++H];
    for (int i = 0; i < 10; i++)
      if (tree[u].son[i]) q[++T] = tree[u].son[i];
    if (u == 0)
      tree[u].fail = -1;
    else if (tree[u].fa == 0)
      tree[u].fail = 0;
    else
      tree[u].fail = tree[tree[tree[u].fa].fail].son[tree[u].ch];
    if (u)
      for (int i = 0; i < 10; i++)
        if (tree[u].son[i] == 0) tree[u].son[i] = tree[tree[u].fail].son[i];
  }
}
int val[2001][16001], f[2001][16001];
int main() {
  read();
  for (int i = 0; i < L; i++) {
    bool head_same = true;
    for (int j = i + 1; j < L; j++)
      if (a[j] != b[j]) {
        head_same = false;
        break;
      }
    if (head_same) {
      int p = 0;
      for (int j = L - 1; j > i; j--) p = son(p, a[j]);
      for (int j = a[i]; j < b[i]; j++) tree[son(p, j)].war.push_back(i);
      break;
    }
    if (a[i] != 0) {
      int p = 0;
      for (int j = L - 1; j > i; j--)
        if (p != 0 || a[j] != 0) p = son(p, a[j]);
      for (int j = a[i]; j < 10; j++) tree[son(p, j)].war.push_back(i);
      a[i] = 10;
      for (int j = i; j < L; j++)
        if (a[j] > 9) {
          a[j + 1]++;
          a[j] -= 10;
        }
    }
    if (b[i] != 0) {
      int p = 0;
      for (int j = L - 1; j > i; j--)
        if (p != 0 || b[j] != 0) p = son(p, b[j]);
      for (int j = 0; j < b[i]; j++) tree[son(p, j)].war.push_back(i);
      b[i] = 0;
    }
  }
  BFS();
  for (int i = 0; i <= n; i++)
    for (int j : tree[i].war) val[j][i]++;
  for (int i = 0; i <= N; i++)
    for (int j = 2; j <= n + 1; j++) val[i][q[j]] += val[i][tree[q[j]].fail];
  for (int i = 1; i <= N; i++)
    for (int j = 0; j <= n; j++) val[i][j] += val[i - 1][j];
  for (int i = 0; i <= n; i++) f[0][i] = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k < 10; k++)
        f[i][j] = std::max(
            f[i][j], f[i - 1][tree[j].son[k]] + val[i - 1][tree[j].son[k]]);
  printf("%d\n", f[N][0]);
  for (int i = N, j = 0, u; i; i--, j = tree[j].son[u]) {
    u = 0;
    while (f[i][j] != f[i - 1][tree[j].son[u]] + val[i - 1][tree[j].son[u]])
      u++;
    putchar(u + 48);
  }
  putchar('\n');
  return 0;
}

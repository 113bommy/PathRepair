#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
const int S = 19;
vector<int> e[M];
int fa[M][S], dep[M], n;
inline void rd(int &res) {
  res = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do res = (res << 1) + (res << 3) + (c ^ 48);
  while (c = getchar(), c >= 48);
}
inline void print(int k) {
  if (!k) return;
  print(k / 10);
  putchar((k % 10) ^ 48);
}
inline void sc(int x) {
  if (x == 0) putchar('0');
  print(x);
  putchar('\n');
}
void Up(int &x, int step) {
  for (int i = S - 1; i >= 0; i--) {
    if (step & (1 << i)) x = fa[x][i];
  }
}
int LCA(int a, int b) {
  if (a == b) return a;
  if (dep[a] < dep[b]) swap(a, b);
  Up(a, dep[a] - dep[b]);
  if (a == b) return a;
  for (int i = S - 1; i >= 0; i--) {
    if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
  }
  return fa[a][0];
}
int main() {
  rd(n);
  int i, x;
  int A = 1, B = 1, mxdis = 0;
  for (i = 2; i <= n; i++) {
    rd(x);
    fa[i][0] = x;
    for (int j = 1; j < S; j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
    dep[i] = dep[x] + 1;
    int a = dep[i] + dep[A] - 2 * dep[LCA(i, A)];
    if (a > mxdis) {
      mxdis = a;
      B = i;
    } else {
      int b = dep[i] + dep[B] - 2 * dep[LCA(i, B)];
      if (b > mxdis) {
        mxdis = b;
        A = i;
      }
    }
    sc(mxdis);
  }
  return 0;
}

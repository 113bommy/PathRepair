#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:16777216")
void ASS(bool b) {
  if (!b) ++*(int*)0;
}
const int N = 1 << 17;
int G;
int f[N];
int OnStack[N];
vector<int> g[N];
int gcd(int a, int b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  while (a) {
    int c = b % a;
    b = a;
    a = c;
  }
  return b;
}
int mabs(int x) { return max(x, -x); }
void dfs(int x, int d) {
  OnStack[x] = 1;
  f[x] = d;
  for (int i = 0; i < (int)(g[x].size()); ++i) {
    int y = g[x][i];
    if (f[y]) {
      if (OnStack[y]) {
        G = gcd(G, d - f[y] + 1);
      } else
        G = gcd(G, mabs(f[y] - d) - 1);
    } else
      dfs(y, d + 1);
  }
  OnStack[x] = 0;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (int)(m); ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
  }
  dfs(1, 1);
  while (G == 0)
    ;
  ;
  ;
  ASS(G != 0);
  vector<int> v;
  for (int i = 1; i <= n; i++)
    if (f[i] && (f[i] - 1) % G == 0) v.push_back(i);
  printf("%d\n", G);
  printf("%d\n", v.size());
  for (int i = 0; i < (int)(v.size()); ++i) {
    if (i) printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}

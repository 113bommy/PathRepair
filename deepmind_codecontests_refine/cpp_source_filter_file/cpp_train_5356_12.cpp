#include <bits/stdc++.h>
const int maxn = 310;
int n, p;
bool vis[maxn];
void Solve() {
  int i, x;
  scanf("%d%d", &n, &p);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (vis[x % p]) {
      printf("%d\n", i);
      return;
    }
    vis[x % p] = true;
  }
  printf("-1\n");
}
int main() { Solve(); }

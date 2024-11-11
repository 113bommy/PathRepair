#include <bits/stdc++.h>
using namespace std;
int n, fa[110], f[110], d[110];
int find(int x) {
  if (fa[x] != x) fa[x] = find(fa[x]);
  return fa[x];
}
void unin(int x, int y) {
  int a = find(x);
  int b = find(y);
  if (a != b) f[a] = b;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
    if (i - d[i] > 0) unin(i, i - d[i]);
    if (i + d[i] <= n) unin(i, i + d[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) != find(f[i])) {
      printf("NO\n");
      exit(0);
    }
  }
  printf("YES\n");
  return 0;
}

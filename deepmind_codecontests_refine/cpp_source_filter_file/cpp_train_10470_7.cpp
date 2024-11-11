#include <bits/stdc++.h>
int r[10010], ans;
int root(int ru) {
  if (ru == r[ru]) return ru;
  return r[ru] = root(r[ru]);
}
void merge(int a, int b) {
  int ra = root(a), rb = root(b);
  if (ra != rb) {
    r[a] = rb;
  }
}
int main() {
  int n, i, a;
  scanf("%d", &n);
  {
    ans = n;
    for (i = 1; i <= n; i++) r[i] = i;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a);
      if (a != i) merge(a, i);
    }
    ans = 0;
    for (i = 1; i <= n; i++)
      if (root(i) == i) ans++;
    printf("%d\n", ans);
  }
  return 0;
}

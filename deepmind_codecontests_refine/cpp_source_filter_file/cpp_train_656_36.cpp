#include <bits/stdc++.h>
using namespace std;
const int MAXN = 107;
int n;
int a[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int s = 0;
  for (int i = 1; i <= n; i++) s += a[i] * a[i];
  printf("%d\n", s);
  fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
  return 0;
}

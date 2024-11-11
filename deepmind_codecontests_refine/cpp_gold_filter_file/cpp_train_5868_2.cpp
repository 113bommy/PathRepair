#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int n, m;
struct Tside {
  int y;
  Tside *next;
} * h[maxn];
int x[maxn], y[maxn];
int tim[maxn];
int f[maxn];
long long tot1 = 0, tot2 = 0;
void ins(int x, int y) {
  Tside *tmp = h[x];
  h[x] = new (Tside);
  h[x]->y = y;
  h[x]->next = tmp;
  tmp = h[y];
  h[y] = new (Tside);
  h[y]->y = x;
  h[y]->next = tmp;
}
void dfs(int k, int fl) {
  if (tim[k] != 0) {
    if (fl - 3 == tim[k]) tot1++;
    return;
  }
  tim[k] = fl;
  Tside *tmp = h[k];
  while (tmp != NULL) {
    dfs(tmp->y, fl + 1);
    tmp = tmp->next;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  tot2 = (long long)n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++) h[i] = NULL;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= m; i++) {
    tot2 -= (n - 2);
    tot2 += f[x[i]] + f[y[i]];
    f[x[i]]++;
    f[y[i]]++;
  }
  printf("%I64d\n", tot2);
  return 0;
}

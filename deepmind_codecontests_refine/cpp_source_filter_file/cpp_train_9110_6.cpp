#include <bits/stdc++.h>
using namespace std;
int const maxn = 200001;
int a[maxn];
int id[maxn];
int main() {
  int n, m, s, d;
  scanf("%d %d %d %d", &n, &m, &s, &d);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int sz = 0;
  a[0] = -1;
  a[n + 1] = m + 1;
  for (int i = 1; i <= n + 1; i++)
    if (a[i] - a[i - 1] - 1 > s) id[sz++] = i;
  if (id[0] == 0) return puts("IMPOSSIBLE"), 0;
  if (a[n] + 1 - a[id[sz - 1]] + 1 > d) return puts("IMPOSSIBLE"), 0;
  for (int i = 1; i < sz; i++)
    if (a[id[i] - 1] + 1 - a[id[i - 1]] + 1 > d) return puts("IMPOSSIBLE"), 0;
  int cur = 0;
  if (id[sz - 1] != n + 1) id[sz++] = n + 1;
  for (int i = 1; i < sz; i++) {
    int val = a[id[i - 1]] - 1 - cur;
    cur = a[id[i - 1]] - 1;
    int t = a[id[i] - 1] + 1;
    t = t - cur;
    printf("%s %d\n", "RUN", val);
    printf("%s %d\n", "JUMP", t);
    cur = a[id[i] - 1] + 1;
  }
  if (cur != m) {
    printf("%s %d\n", "RUN", m - cur);
  }
  return 0;
}

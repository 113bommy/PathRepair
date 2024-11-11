#include <bits/stdc++.h>
int u[20], v[20], seat[20];
long long num[(1 << 16)];
int n, m;
long long y;
void input() {
  int i, a, b;
  memset(seat, 0, sizeof(seat));
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    seat[a - 1] |= 1 << (b - 1);
  }
}
void init() {
  int i;
  m = (1 << n) - 1;
  for (i = 0; i < n; i++) u[i] = v[i] = m;
  memset(num, -1, sizeof(num));
}
int pos(int state, int k) { return (state >> k) & 1; }
long long dfs(int state, int k) {
  int i;
  if (num[state] > -1) return num[state];
  if (k == n) return num[state] = 1;
  num[state] = 0;
  for (i = 0; i < n; i++)
    if (!pos(state, i) && !(state & seat[i]) && pos(v[k], i) && pos(u[i], k))
      num[state] += dfs(state | (1 << i), k + 1);
  return num[state];
}
int find(int state) {
  int i;
  for (i = 0; i < n; i++)
    if (pos(state, i)) return i + 1;
  return -1;
}
void print() {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (v[j] == m) {
        u[i] = 1 << j;
        v[j] = 1 << i;
        memset(num, -1, sizeof(num));
        dfs(0, 0);
        if (num[0] < y) {
          y -= num[0];
          u[i] = v[j] = m;
        } else
          break;
      }
  for (i = 0; i < n; i++) printf("%d%c", find(u[i]), i == n - 1 ? '\n' : ' ');
}
void deal() {
  init();
  dfs(0, 0);
  y -= 2000;
  if (num[0] < y)
    puts("The times have changed");
  else
    print();
}
int main(void) {
  while (scanf("%d%lld%d", &n, &y, &m) == 3) {
    input();
    deal();
  }
  return 0;
}

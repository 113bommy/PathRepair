#include <bits/stdc++.h>
const int maxn = 2000005;
int a[maxn];
int b[maxn];
int pos[maxn / 2];
void Max(int &a, int b) {
  if (b > a) a = b;
}
bool ok(int a, int b, int c) {
  if (a <= b && (c > b || c < a)) return true;
  if (a > b && c > a && c < b) return true;
  return false;
}
int gao(int a[], int n) {
  int len = 0;
  int p1 = 0, p2 = -1;
  int i;
  for (i = 0; i < n; i++) {
    Max(len, p2 - p1 + 1);
    if (pos[a[i]] == -1) {
      p1 = i + 1;
      p2 = p1 - 1;
      continue;
    }
    while (p1 <= p2 && !ok(pos[a[p1]], pos[a[p2]], pos[a[i]])) p1++;
    p2 = i;
  }
  Max(len, p2 - p1 + 1);
  return len;
}
int main() {
  int n, m;
  int i, j;
  int tot;
  while (scanf("%d%d", &n, &m) != -1) {
    memset(pos, -1, sizeof(pos));
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      a[i]--;
      a[i + n] = a[i];
    }
    tot = 0;
    for (i = 0; i < m; i++) {
      scanf("%d", &b[i]);
      b[i]--;
      pos[b[i]] = i;
    }
    int ans = gao(a, n * 2);
    printf("%d\n", ans);
  }
  return 0;
}

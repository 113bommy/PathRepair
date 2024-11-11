#include <bits/stdc++.h>
using namespace std;
struct node {
  int t, o, c;
};
char s[2000010];
int n, o[2000010], c[2000010], t[2000010];
void build(int id, int l, int r) {
  if (r - l < 1) {
    if (s[r] == '(')
      o[id] = 1;
    else
      c[id] = 1;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  int temp = min(o[2 * id], c[2 * id + 1]);
  t[id] = t[2 * id] + t[2 * id + 1] + temp;
  o[id] = o[2 * id] + o[2 * id + 1] - temp;
  c[id] = c[2 * id] + c[2 * id + 1] - temp;
}
node query(int x, int y, int l, int r, int id) {
  if (y < l || x > r || r < l) return {0, 0, 0};
  if (r - l < 1) {
    if (s[r] == '(')
      return {0, 1, 0};
    else
      return {0, 0, 1};
  }
  if (x <= l && y >= r) return {t[id], o[id], c[id]};
  node na, nb;
  na = query(x, y, l, (l + r) / 2, 2 * id);
  nb = query(x, y, (l + r) / 2 + 1, r, 2 * id + 1);
  int t = min(na.o, nb.c);
  return {na.t + nb.t + t, na.o + nb.o - t, na.c + nb.c - t};
}
int main() {
  int i, x, y, j, num, k, m, w, l, r, p;
  scanf("%s", s);
  n = strlen(s);
  build(1, 0, n - 1);
  scanf("%d", &m);
  for (i = (1); i <= (m); i++) {
    scanf("%d%d", &l, &r);
    node nd = query(l - 1, r - 1, 1 - 1, n - 1, 1);
    printf("%d\n", 2 * nd.t);
  }
  return 0;
}

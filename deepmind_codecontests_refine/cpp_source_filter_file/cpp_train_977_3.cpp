#include <bits/stdc++.h>
int vt[100005], it[100005];
int n;
void update(int pos, int val) {
  int u = pos;
  while (u <= n) {
    if (it[u] < val) it[u] = val;
    u = u + (u & (-u));
  }
}
int query(int pos) {
  int u = pos;
  int res = 0;
  while (u >= 1) {
    if (it[u] > res) res = it[u];
    u = u - (u & (-u));
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int tmp;
    scanf("%d", &tmp);
    vt[tmp] = i;
  }
  for (int i = 1; i <= n; i++) it[i] = 0;
  for (int i = n; i >= 1; i--) {
    int tmp = query(vt[i]);
    update(vt[i], tmp + 1);
  }
  printf("%d", query(n));
  return 0;
}

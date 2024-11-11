#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 7;
const int MAXN = 4e4 + 10;
int n, k;
int a[MAXN];
int s[55][MAXN << 2], lazy[55][MAXN << 2];
void pushDown(int b, int rt) {
  if (s[b][rt] > 0) {
    s[b][rt << 1] += lazy[b][rt];
    s[b][rt << 1 | 1] += lazy[b][rt];
    lazy[b][rt << 1] += lazy[b][rt];
    lazy[b][rt << 1 | 1] += lazy[b][rt];
    lazy[b][rt] = 0;
  }
}
void pushUp(int b, int rt) { s[b][rt] = max(s[b][rt << 1], s[b][rt << 1 | 1]); }
void update(int L, int R, int b, int c, int l, int r, int rt) {
  if (l >= L && r <= R) {
    s[b][rt] += c;
    lazy[b][rt] += c;
    return;
  }
  int m = (l + r) / 2;
  pushDown(b, rt);
  if (L <= m) update(L, R, b, c, l, m, rt << 1);
  if (R > m) update(L, R, b, c, m + 1, r, rt << 1 | 1);
  pushUp(b, rt);
}
int query(int L, int R, int b, int l, int r, int rt) {
  if (l >= L && r <= R) {
    return s[b][rt];
  }
  int m = (l + r) / 2;
  pushDown(b, rt);
  int res = 0;
  if (L <= m) res = query(L, R, b, l, m, rt << 1);
  if (R > m) res = max(res, query(L, R, b, m + 1, r, rt << 1 | 1));
  pushUp(b, rt);
  return res;
}
int last[MAXN];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    update(last[a[i]] + 1, i, 0, 1, 1, n, 1);
    for (int j = 1; j <= min(k, i); j++) {
      update(last[a[i]] + 1, i, j, 1, 1, n + 1, 1);
      int res = query(j, i, j - 1, 1, n + 1, 1);
      if (i == n) ans = max(ans, res);
      update(i + 1, i + 1, j, res, 1, n + 1, 1);
    }
    last[a[i]] = i;
  }
  printf("%d\n", ans);
  return 0;
}

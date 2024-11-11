#include <bits/stdc++.h>
using namespace std;
int n, m, a[300010];
int ch[300010 * 25][2], sum[300010 * 25], tot, rt[300010];
void insert(int &x, int y, int l, int r, int val) {
  x = ++tot;
  ch[x][0] = ch[y][0], ch[x][1] = ch[y][1], sum[x] = sum[y] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (val <= mid)
    insert(ch[x][0], ch[y][0], l, mid, val);
  else
    insert(ch[x][1], ch[y][1], mid + 1, r, val);
}
int ask(int x, int y, int l, int r, int k) {
  if (l == r) {
    if (sum[x] - sum[y] > k) return l;
    return -1;
  }
  int mid = (l + r) >> 1;
  if (sum[ch[x][0]] - sum[ch[y][0]] > k) {
    int ans = ask(ch[x][0], ch[y][0], l, mid, k);
    if (ans > 0) return ans;
  }
  if (sum[ch[x][1]] - sum[ch[y][1]] > k) {
    int ans = ask(ch[x][1], ch[y][1], mid + 1, r, k);
    if (ans > 0) return ans;
  }
  return -1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), insert(rt[i], rt[i - 1], 1, n, a[i]);
  for (int i = 1, l, r, k; i <= m; i++) {
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", ask(rt[r], rt[l - 1], 1, n, (r - l + 1) / k));
  }
  return 0;
}

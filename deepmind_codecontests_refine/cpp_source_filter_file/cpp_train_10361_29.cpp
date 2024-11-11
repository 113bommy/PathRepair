#include <bits/stdc++.h>
using namespace std;
struct data {
  int id;
  long long int r, h;
} ar[100000 + 5];
long long int dp[100000 + 5], tree[4 * 100000 + 5];
bool cmp(data a, data b) {
  if ((a.r * a.r * a.h) == (b.r * b.r * b.h)) return a.id < b.id;
  return (a.r * a.r * a.h) < (b.r * b.r * b.h);
}
void update(int idx, int st, int ed, int s, long long int v) {
  if (st > s || ed < s) return;
  if (st >= s && ed <= s) {
    tree[idx] = v;
    return;
  }
  int mid = (st + ed) >> 1;
  int l = idx << 1;
  int r = l + 1;
  update(l, st, mid, s, v);
  update(r, mid + 1, ed, s, v);
  tree[idx] = max(tree[l], tree[r]);
}
long long int query(int idx, int st, int ed, int s, int e) {
  if (st > e || ed < s) return 0;
  if (st >= s && ed <= e) return tree[idx];
  int mid = (st + ed) >> 1;
  int l = idx << 1;
  int r = l + 1;
  return max(query(l, st, mid, s, e), query(r, mid + 1, ed, s, e));
}
int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld %lld", &ar[i].r, &ar[i].h);
    ar[i].id = i + 1;
  }
  sort(ar, ar + n, cmp);
  for (i = 0; i < n; i++) {
    long long int tmp = query(1, 1, n, 1, ar[i].id - 1);
    dp[i] = tmp + ar[i].r * ar[i].r * ar[i].h;
    update(1, 1, n, ar[i].id, dp[i]);
  }
  long long int ans = 0;
  for (i = 0; i < n; i++) ans = max(ans, dp[i]);
  printf("%0.10lf\n", acos(-1.0) * ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 400100;
int a[maxn];
struct Qry {
  int r1, c1, r2, c2, id;
} q[maxn];
int n, Q;
int ST[maxn][20], lg[maxn];
int ans[maxn];
int qrymin(int l, int r) {
  if (l > r) swap(l, r);
  int L = lg[r - l + 1];
  return min(ST[l][L], ST[r - (1 << L) + 1][L]);
}
int st[maxn], tp;
int go(Qry t, int p) {
  int w = min(t.c1, qrymin(st[p], t.r1));
  int cur = abs(st[p] - t.r1) + abs(st[p] - t.r2);
  if (w != a[st[p]]) cur++;
  w = a[st[p]];
  cur += abs(w - t.c2);
  return cur;
}
void solve(Qry c, int l, int r) {
  l--, r++;
  while (l + 5 < r) {
    int lm = (l + l + r) / 3, rm = (l + r + r) / 3;
    if (go(c, lm) > go(c, rm))
      l = lm;
    else
      r = rm;
  }
  for (int i = l + 1; i <= r - 1; i++) ans[c.id] = min(ans[c.id], go(c, i));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  lg[0] = -1;
  for (int i = 1; i <= n; i++)
    cin >> a[i], ST[i][0] = a[i], lg[i] = lg[i / 2] + 1;
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      ST[i][j] = min(ST[i][j - 1], ST[i + (1 << j - 1)][j - 1]);
  }
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    cin >> q[i].r1 >> q[i].c1 >> q[i].r2 >> q[i].c2;
    q[i].id = i;
    ans[i] = abs(q[i].r2 - q[i].r1) + 1 + q[i].c2;
    ans[i] = min(ans[i], abs(min(q[i].c1, qrymin(q[i].r1, q[i].r2)) - q[i].c2) +
                             abs(q[i].r2 - q[i].r1));
  }
  sort(q + 1, q + Q + 1, [&](Qry a, Qry b) { return a.r2 < b.r2; });
  tp = 0;
  int j = 1, p;
  for (int i = 1; i <= n; i++) {
    while (tp && a[st[tp]] >= a[i]) tp--;
    st[++tp] = i;
    while (j != Q + 1 && q[j].r2 == i) {
      if (q[j].r1 <= q[j].r2) {
        p = lower_bound(st + 1, st + tp + 1, q[j].r1) - st;
        solve(q[j], 1, p - 1);
        solve(q[j], p, tp);
      } else {
        solve(q[j], 1, tp);
      }
      j++;
    }
  }
  tp = 0, j = Q;
  for (int i = n; i; i--) {
    while (tp && a[st[tp]] >= a[i]) tp--;
    st[++tp] = i;
    while (j != 0 && q[j].r2 == i) {
      if (q[j].r1 > q[j].r2) {
        int L = 1, R = tp;
        while (L != R) {
          int mid = L + R >> 1;
          if (st[mid] <= q[j].r1)
            R = mid;
          else
            L = mid + 1;
        }
        p = L;
        solve(q[j], 1, p - 1);
        solve(q[j], p, tp);
      } else {
        solve(q[j], 1, tp);
      }
      j--;
    }
  }
  for (int i = 1; i <= Q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}

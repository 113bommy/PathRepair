#include <bits/stdc++.h>
using namespace std;
const int N = 3000 + 10;
int n, a[N], dt[N], st[N][14], pos[N][14], mark[N], lg[N];
pair<int, int> nd[N];
bool cmp1(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first > b.first;
}
bool unfix(int l, int r) { return l > r; }
int query(int l, int r) {
  int lg1 = lg[r - l + 1];
  return max(st[l][lg1], st[r - (1 << lg1) + 1][lg1]);
}
bool ok(int a, int b, int c, int d, int e, int f) {
  if (a != d) return d > a;
  if (b != e) return e > b;
  if (c != f) return f > c;
  return 1;
}
int posquery(int l, int r) {
  int lg1 = lg[r - l + 1];
  if (st[l][lg1] > st[r - (1 << lg1) + 1][lg1])
    return pos[l][lg1];
  else
    return pos[r - (1 << lg1) + 1][lg1];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), nd[i] = {a[i], i};
  sort(nd + 1, nd + n + 1, cmp1);
  for (int i = 1; i <= n; i++) a[i] = nd[i].first;
  for (int i = n; i >= 1; i--)
    dt[i] = a[i] - a[i + 1], st[i][0] = dt[i], pos[i][0] = i;
  st[n][0] = dt[n];
  pos[n][0] = n;
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  int LG = lg[n];
  for (int j = 1; j <= LG; j++) {
    for (int i = 1; i <= n; i++) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      if (st[i][j - 1] > st[i + (1 << (j - 1))][j - 1])
        pos[i][j] = pos[i][j - 1];
      else
        pos[i][j] = pos[i + (1 << (j - 1))][j - 1];
    }
  }
  int ans1 = 0, ans2 = 0, ans3 = 0;
  int pos1 = 0, pos2 = 0, pos3 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int cnta = i, cntb = j - i;
      if (cnta > 2 * cntb || cntb > 2 * cnta) continue;
      if (unfix(max((cnta + 1) / 2, (cntb + 1) / 2),
                min(min(2 * cnta, 2 * cntb), n)))
        continue;
      int l = max(j + 1, j + max((cnta + 1) / 2, (cntb + 1) / 2)),
          r = min(j + min(2 * cnta, 2 * cntb), n);
      if (unfix(l, r)) continue;
      int gap1 = a[i] - a[i + 1], gap2 = a[j] - a[j + 1], gap3 = query(l, r);
      if (ok(ans1, ans2, ans3, gap1, gap2, gap3)) {
        ans1 = gap1;
        ans2 = gap2;
        ans3 = gap3;
        pos1 = i;
        pos2 = j;
        pos3 = posquery(l, r);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i <= pos1)
      mark[nd[i].second] = 1;
    else if (i <= pos2)
      mark[nd[i].second] = 2;
    else if (i <= pos3)
      mark[nd[i].second] = 3;
    else
      mark[nd[i].second] = -1;
  }
  for (int i = 1; i <= n; i++) cout << mark[i] << " ";
  return 0;
}

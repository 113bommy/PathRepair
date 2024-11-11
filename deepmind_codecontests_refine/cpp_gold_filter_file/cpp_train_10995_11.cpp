#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
int n, a[N], idx[N], l1, l2, l3, det1, det2, det3;
pair<int, int> mx[N][N];
bool cmp(int x, int y) { return a[x] < a[y]; }
void upd(pair<int, int>& cur, pair<int, int> x) {
  if (cur.first <= x.first) cur = x;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    idx[i] = i;
  }
  sort(idx, idx + n + 1, cmp);
  memset(mx, 0, sizeof(mx));
  for (int i = 1; i <= n; i++) {
    pair<int, int> cur = make_pair(a[idx[i]] - a[idx[i - 1]], i);
    for (int j = i; j <= n; j++) {
      upd(cur, make_pair(a[idx[j]] - a[idx[j - 1]], j));
      upd(mx[i][j], cur);
    }
  }
  det1 = det2 = det3 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = (i + 1) / 2; j <= 2 * i; j++) {
      if (i > 2 * (n - i - j) || j > 2 * (n - i - j)) continue;
      int rmn = min(2 * i, 2 * j), rmx = max((i + 1) / 2, (j + 1) / 2);
      int x = a[idx[n - i + 1]] - a[idx[n - i]];
      int y = a[idx[n - i - j + 1]] - a[idx[n - i - j]];
      int z = mx[max(1, n - i - j - rmn + 1)][n - i - j - rmx + 1].first;
      if (x > det1 || (x == det1 && y > det2) ||
          (x == det1 && y == det2 && z > det3)) {
        det1 = x;
        det2 = y;
        det3 = z;
        l1 = i;
        l2 = j;
        l3 = n - i - j -
             mx[max(1, n - i - j - rmn + 1)][n - i - j - rmx + 1].second + 1;
      }
    }
  }
  for (int i = n; i > 0; i--) {
    if (l1)
      a[idx[i]] = 1, l1--;
    else if (l2)
      a[idx[i]] = 2, l2--;
    else if (l3)
      a[idx[i]] = 3, l3--;
    else
      a[idx[i]] = -1;
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  puts("");
}
int main() {
  solve();
  return 0;
}

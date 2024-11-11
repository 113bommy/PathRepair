#include <bits/stdc++.h>
using namespace std;
int n, q, a[5005], s = (1 << 8), l[100005], r[100005], b[5005], c[5005], k,
                   dp1[300][300][10], dp2[300][300][20], w[100005];
vector<pair<int, int> > ans;
void Gen(int p, int l, int r, int d) {
  if (l == r) {
    dp1[l][r][d] = b[p + l];
    return;
  }
  int mid = (l + r) / 2;
  Gen(p, l, mid, d + 1);
  Gen(p, mid + 1, r, d + 1);
  int x1 = 0, x2 = 0, y1, y2;
  while (x1 <= mid - l || x2 <= r - mid - 1) {
    y1 = 0, y2 = 0;
    while (x1 + y1 <= mid - l || x2 + y2 <= r - mid - 1) {
      if (x2 + y2 > r - mid - 1)
        dp1[l + x1 + x2][r - y1 - y2][d] = dp1[l + x1][mid - y1][d + 1];
      else if (x1 + y1 > mid - l)
        dp1[l + x1 + x2][r - y1 - y2][d] = dp1[mid + 1 + x2][r - y2][d + 1];
      else {
        ans.push_back(
            {dp1[l + x1][mid - y1][d + 1], dp1[mid + 1 + x2][r - y2][d + 1]});
        k++;
        dp1[l + x1 + x2][r - y1 - y2][d] = k;
      }
      if (x1 + y1 <= mid - l &&
          (x2 + y2 > r - mid - 1 || b[p + mid - y1] >= b[p + r - y2]))
        y1++;
      else
        y2++;
    }
    if (x1 <= mid - l &&
        (x2 > r - mid - 1 || b[p + l + x1] <= b[p + mid + 1 + x2]))
      c[p + l + x1 + x2] = b[p + l + x1], x1++;
    else
      c[p + l + x1 + x2] = b[p + mid + 1 + x2], x2++;
  }
  for (int i = p + l; i <= p + r; i++) b[i] = c[i];
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> q;
  k = n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]] = i;
  }
  for (int i = 1; i <= n; i += s) {
    Gen(i, 0, min(n, i + s - 1) - i, 0);
    for (int j = 0; j <= min(n, i + s - 1) - i; j++) {
      for (int k = j; k <= min(n, i + s - 1) - i; k++) {
        dp2[j][k][i / s] = dp1[j][k][0];
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    int last = 0;
    for (int j = 1; j <= n; j += s) {
      int lt = j, rt = min(n, j + s - 1);
      if (b[lt] > r || b[rt] < l) continue;
      int first, second;
      first = lower_bound(b + lt, b + rt + 1, l) - (b + lt);
      second = upper_bound(b + lt, b + rt + 1, r) - (b + lt + 1);
      if (first > second) second++;
      if (last) {
        k++;
        ans.push_back({last, dp2[first][second][j / s]});
        last = k;
      } else {
        last = dp2[first][second][j / s];
      }
    }
    w[i] = last;
  }
  cout << n + ans.size() << '\n';
  for (pair<int, int> i : ans) cout << i.first << ' ' << i.second << '\n';
  for (int i = 1; i <= q; i++) cout << w[i] << ' ';
}

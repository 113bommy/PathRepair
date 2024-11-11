#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int K = 5;
const int INF = 1e9;
int a[N + 7][K + 2];
int qt314[K + 2];
struct SEG {
  int tree[4 * N + 7][2];
  int query(int ss, int se, int si, int qs, int qe, bool fl) {
    if (qs > qe || ss > qe || qs > se) {
      return fl == 0 ? INF : -INF;
    }
    if (qs <= ss && se <= qe) {
      return tree[si][fl];
    }
    int t1 = query(ss, ((ss + se) >> 1), si * 2, qs, qe, fl);
    int t2 = query(((ss + se) >> 1) + 1, se, si * 2 + 1, qs, qe, fl);
    return fl == 0 ? min(t1, t2) : max(t1, t2);
  }
  void upd(int ss, int se, int si, int id, int k) {
    if (ss == se) {
      tree[si][0] = tree[si][1] = k;
      return;
    }
    if (id <= ((ss + se) >> 1)) {
      upd(ss, ((ss + se) >> 1), si * 2, id, k);
    } else {
      upd(((ss + se) >> 1) + 1, se, si * 2 + 1, id, k);
    }
    tree[si][0] = min(tree[si * 2][0], tree[si * 2 + 1][0]);
    tree[si][1] = max(tree[si * 2][1], tree[si * 2 + 1][1]);
  }
} seg[1 << K];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int mask = 0; mask < (1 << k); mask++) {
    for (int i = 1; i <= n; i++) {
      int sum = 0;
      for (int j = 1; j <= k; j++) {
        if (((mask >> (j - 1)) & 1) == 0) {
          sum += a[i][j];
        } else {
          sum -= a[i][j];
        }
      }
      seg[mask].upd(1, n, 1, i, sum);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int i;
      scanf("%d", &i);
      for (int j = 1; j <= k; j++) {
        scanf("%d", &qt314[j]);
      }
      for (int mask = 0; mask < (1 << k); mask++) {
        int sum = 0;
        for (int j = 1; j <= k; j++) {
          if (((mask >> (j - 1)) & 1) == 0) {
            sum += qt314[j];
          } else {
            sum -= qt314[j];
          }
        }
        seg[mask].upd(1, n, 1, i, sum);
      }
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      int ans = -INF;
      for (int mask = 0; mask < (1 << k); ++mask) {
        int minv = seg[mask].query(1, n, 1, l, r, 0);
        int maxv = seg[mask].query(1, n, 1, l, r, 1);
        ans = max(ans, maxv - minv);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}

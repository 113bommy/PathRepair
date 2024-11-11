#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
class SegmentTree {
 public:
  int v[4 * maxn + 1];
  void add(int o, int l, int r, int t, int tv) {
    if (l == r) {
      v[o] += tv;
    } else {
      int mid = (l + r) / 2;
      if (t <= mid) {
        add(o * 2, l, mid, t, tv);
      } else {
        add(o * 2 + 1, mid + 1, r, t, tv);
      }
      v[o] = v[o * 2] + v[o * 2 + 1];
    }
  }
  int getMin(int o, int l, int r, int tl, int tr) {
    if (tl > tr || !v[o]) {
      return 0;
    }
    int mid = (l + r) / 2;
    if (l == r) {
      return l;
    } else if (l == tl && r == tr) {
      if (v[o * 2]) {
        return getMin(o * 2, l, mid, l, mid);
      } else {
        return getMin(o * 2 + 1, mid + 1, r, mid + 1, r);
      }
    } else {
      if (tl <= mid) {
        int t = getMin(o * 2, l, mid, tl, min(tr, mid));
        if (t) return t;
      }
      if (tr > mid) {
        int t = getMin(o * 2 + 1, mid + 1, r, max(tl, mid + 1), tr);
        if (t) return t;
      }
      return 0;
    }
  }
};
int now[maxn + 1];
int solve(int n, bool a[], int x) {
  static SegmentTree pos[2];
  for (int i = 1; i <= n; i++) {
    pos[a[i]].add(1, 1, n, i, 1);
  }
  int ans = 0;
  for (int i = 1, o = 0; i <= n; i++, x = !x) {
    int p = pos[x].getMin(1, 1, n, o + 1, n),
        q = pos[x].getMin(1, 1, n, 1, o - 1);
    if (p && !pos[x].getMin(1, 1, n, p + 1, n) && q &&
        pos[x].getMin(1, 1, n, q + 1, n)) {
      ans++;
      o = q;
    } else if (p) {
      o = p;
    } else {
      ans++;
      o = q;
    }
    pos[x].add(1, 1, n, o, -1);
    now[i] = o;
  }
  return ans;
}
int main() {
  static char s[maxn + 2];
  static int cnt[2];
  static bool a[maxn + 1];
  int n;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = s[i] == 'R';
    cnt[a[i]]++;
  }
  static int ans[maxn + 1];
  ans[0] = n + 1;
  if (cnt[0] >= cnt[1]) {
    int t = solve(n, a, 0);
    if (ans[0] > t) {
      ans[0] = t;
      memcpy(ans + 1, now + 1, n * sizeof(int));
    }
  }
  if (cnt[1] >= cnt[0]) {
    int t = solve(n, a, 1);
    if (ans[0] > t) {
      ans[0] = t;
      memcpy(ans + 1, now + 1, n * sizeof(int));
    }
  }
  printf("%d\n", ans[0]);
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

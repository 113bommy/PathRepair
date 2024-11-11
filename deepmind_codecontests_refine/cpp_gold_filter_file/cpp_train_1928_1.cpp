#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
char s[N];
int n, q, k;
struct node {
  int cnt[10][10];
  int lv, rv, lazy;
};
struct SegmentTree {
  inline int get_id(int l, int r) { return (l + r) | (l != r); }
  node a[2 * N];
  void up(int l, int r) {
    int mid = l + r >> 1;
    int rt = get_id(l, r), lr = get_id(l, mid), rr = get_id(mid + 1, r);
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++)
        a[rt].cnt[i][j] = a[lr].cnt[i][j] + a[rr].cnt[i][j];
    a[rt].cnt[a[lr].rv][a[rr].lv]++;
    a[rt].lv = a[lr].lv;
    a[rt].rv = a[rr].rv;
  }
  void build(int l, int r) {
    int rt = get_id(l, r);
    a[rt].lazy = -1;
    if (l == r) {
      a[rt].lv = a[rt].rv = s[l] - 'a';
      memset(a[rt].cnt, 0, sizeof(a[rt].cnt));
      return;
    }
    int mid = l + r >> 1;
    build(l, mid);
    build(mid + 1, r);
    up(l, r);
  }
  void down(int l, int r) {
    int mid = l + r >> 1;
    int rt = get_id(l, r), lr = get_id(l, mid), rr = get_id(mid + 1, r);
    if (a[rt].lazy == -1) return;
    memset(a[lr].cnt, 0, sizeof(a[lr].cnt));
    memset(a[rr].cnt, 0, sizeof(a[rr].cnt));
    a[lr].lazy = a[lr].lv = a[lr].rv = a[rr].lazy = a[rr].lv = a[rr].rv =
        a[rt].lazy;
    a[rt].lazy = -1;
  }
  void update(int L, int R, int val, int l, int r) {
    int rt = get_id(l, r);
    int mid = l + r >> 1;
    if (L <= l && r <= R) {
      memset(a[rt].cnt, 0, sizeof a[rt].cnt);
      a[rt].lazy = a[rt].lv = a[rt].rv = val;
      return;
    }
    down(l, r);
    if (L <= mid) update(L, R, val, l, mid);
    if (R > mid) update(L, R, val, mid + 1, r);
    up(l, r);
  }
} S;
int main(void) {
  while (~scanf("%d %d %d", &n, &q, &k)) {
    scanf("%s", s + 1);
    S.build(1, n);
    for (int i = 1; i <= q; i++) {
      int op;
      scanf("%d", &op);
      if (op == 1) {
        int l, r;
        char ss[5];
        scanf("%d %d", &l, &r);
        scanf("%s", ss);
        S.update(l, r, ss[0] - 'a', 1, n);
      } else {
        scanf("%s", s);
        int ans = n;
        for (int i = 0; s[i]; i++)
          for (int j = i + 1; s[j]; j++)
            ans -= S.a[S.get_id(1, n)].cnt[s[i] - 'a'][s[j] - 'a'];
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}

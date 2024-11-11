#include <bits/stdc++.h>
using namespace std;
const int NR = 1e6 + 10;
const int MAX = 5e5;
int n, q;
int a[NR];
struct Seg {
  int tr[NR << 2], lz[NR << 2];
  void update(int rt) { tr[rt] = min(tr[rt * 2], tr[rt * 2 + 1]); }
  void build(int rt, int l, int r) {
    if (l == r) {
      tr[rt] = l;
      return;
    }
    int mid = (l + r >> 1);
    build(rt * 2, l, mid), build(rt * 2 + 1, mid + 1, r);
    update(rt);
  }
  void push_down(int rt) {
    if (!lz[rt]) return;
    int x = lz[rt];
    tr[rt * 2] += x, tr[rt * 2 + 1] += x;
    lz[rt * 2] += x, lz[rt * 2 + 1] += x;
    lz[rt] = 0;
  }
  void change(int rt, int l, int r, int L, int R, int val) {
    if (l == L && r == R) {
      tr[rt] += val, lz[rt] += val;
      return;
    }
    int mid = (l + r >> 1);
    push_down(rt);
    if (R <= mid)
      change(rt * 2, l, mid, L, R, val);
    else if (L > mid)
      change(rt * 2 + 1, mid + 1, r, L, R, val);
    else
      change(rt * 2, l, mid, L, mid, val),
          change(rt * 2 + 1, mid + 1, r, mid + 1, R, val);
    update(rt);
  }
  int query(int rt, int l, int r, int L, int R) {
    if (l == L && r == R) return tr[rt];
    int mid = (l + r >> 1);
    push_down(rt);
    if (R <= mid)
      return query(rt * 2, l, mid, L, R);
    else if (L > mid)
      return query(rt * 2 + 1, mid + 1, r, L, R);
    else
      return min(query(rt * 2, l, mid, L, mid),
                 query(rt * 2 + 1, mid + 1, r, mid + 1, R));
    update(rt);
  }
} S;
struct Seg2 {
  int tr[NR << 2];
  void Init() { memset(tr, 0, sizeof(tr)); }
  void update(int rt) { tr[rt] = tr[rt * 2] + tr[rt * 2 + 1]; }
  void change(int rt, int l, int r, int x, int val) {
    if (l == r) {
      tr[rt] += val;
      return;
    }
    int mid = (l + r >> 1);
    if (x <= mid)
      change(rt * 2, l, mid, x, val);
    else
      change(rt * 2 + 1, mid + 1, r, x, val);
    update(rt);
  }
  int query(int rt, int l, int r, int L, int R) {
    if (l == L && r == R) return tr[rt];
    int mid = (l + r >> 1);
    if (R <= mid)
      return query(rt * 2, l, mid, L, R);
    else if (L > mid)
      return query(rt * 2 + 1, mid + 1, r, L, R);
    else
      return query(rt * 2, l, mid, L, mid) +
             query(rt * 2 + 1, mid + 1, r, mid + 1, R);
  }
  int find(int rt, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r >> 1);
    if (tr[rt * 2] < x)
      return find(rt * 2 + 1, mid + 1, r, x - tr[rt * 2]);
    else
      return find(rt * 2, l, mid, x);
  }
} T;
int all, min_n = 0x3f3f3f3f;
void insert(int x) {
  S.change(1, -MAX, MAX, x, MAX, -1);
  T.change(1, -MAX, MAX, x, 1);
  all++;
  min_n = min(min_n, x);
}
int query(int pos, int num) {
  int cnt = T.query(1, -MAX, MAX, pos, MAX);
  int min_n = min(num, S.query(1, -MAX, MAX, pos, MAX) + (all - cnt));
  return cnt + min_n;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int main() {
  q = read();
  S.build(1, -MAX, MAX);
  T.Init();
  while (q--) {
    int x = read();
    insert(x);
    if (min_n >= 0) {
      printf("%d\n", query(0, 0));
      continue;
    }
    int l = 1, r = all, ans = -1;
    while (l <= r) {
      int mid = (l + r >> 1);
      if (T.find(1, -MAX, MAX, mid) <= -mid)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    if (ans == -1 || ans == all) {
      printf("%d\n", -all);
      continue;
    }
    int now = T.find(1, -MAX, MAX, ans + 1);
    printf("%d\n", query(now, -ans));
  }
  return 0;
}

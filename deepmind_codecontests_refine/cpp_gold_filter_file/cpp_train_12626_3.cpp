#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long kkk = 0, x = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') c = getchar(), x = -1;
  while (c >= '0' && c <= '9')
    kkk = (kkk << 3) + (kkk << 1) + (c - '0'), c = getchar();
  return kkk * x;
}
long long n, m, lazy[1600001], a[200001], ans;
struct data {
  long long minn, sec, cnt, value;
} tree[1600001];
void up(long long bj) {
  tree[bj].value = tree[bj * 2].value + tree[bj * 2 + 1].value;
  if (tree[bj * 2].minn == tree[bj * 2 + 1].minn) {
    tree[bj].minn = tree[bj * 2].minn;
    tree[bj].cnt = tree[bj * 2].cnt + tree[bj * 2 + 1].cnt;
    tree[bj].sec = min(tree[bj * 2].sec, tree[bj * 2 + 1].sec);
  } else {
    if (tree[bj * 2].minn < tree[bj * 2 + 1].minn) {
      tree[bj].minn = tree[bj * 2].minn;
      tree[bj].cnt = tree[bj * 2].cnt;
      tree[bj].sec = min(tree[bj * 2].sec, tree[bj * 2 + 1].minn);
    } else {
      tree[bj].minn = tree[bj * 2 + 1].minn;
      tree[bj].cnt = tree[bj * 2 + 1].cnt;
      tree[bj].sec = min(tree[bj * 2].minn, tree[bj * 2 + 1].sec);
    }
  }
}
void build(long long l, long long r, long long bj) {
  if (l == r) {
    tree[bj].minn = tree[bj].value = a[l];
    tree[bj].sec = 0x3f3f3f3f3f3f3f3f;
    tree[bj].cnt = 1;
    return;
  }
  long long mid = (l + r) / 2;
  build(l, mid, bj * 2);
  build(mid + 1, r, bj * 2 + 1);
  up(bj);
}
void down(long long l, long long r, long long mid, long long bj) {
  if (!lazy[bj]) return;
  if (lazy[bj] >= tree[bj * 2].minn) {
    tree[bj * 2].value += tree[bj * 2].cnt * (lazy[bj] - tree[bj * 2].minn);
    tree[bj * 2].minn = lazy[bj];
    lazy[bj * 2] = lazy[bj];
  }
  if (lazy[bj] >= tree[bj * 2 + 1].minn) {
    tree[bj * 2 + 1].value +=
        tree[bj * 2 + 1].cnt * (lazy[bj] - tree[bj * 2 + 1].minn);
    tree[bj * 2 + 1].minn = lazy[bj];
    lazy[bj * 2 + 1] = lazy[bj];
  }
  lazy[bj] = 0;
}
void xg(long long l, long long r, long long L, long long R, long long v,
        long long bj) {
  if (tree[bj].minn >= v) return;
  if (L <= l && r <= R) {
    if (tree[bj].sec > v && v > tree[bj].minn) {
      tree[bj].value += (v - tree[bj].minn) * tree[bj].cnt;
      tree[bj].minn = v;
      lazy[bj] = v;
    } else {
      long long mid = (l + r) / 2;
      down(l, r, mid, bj);
      xg(l, mid, L, R, v, bj * 2);
      xg(mid + 1, r, L, R, v, bj * 2 + 1);
      up(bj);
    }
    return;
  }
  long long mid = (l + r) / 2;
  down(l, r, mid, bj);
  if (L <= mid) xg(l, mid, L, R, v, bj * 2);
  if (mid < R) xg(mid + 1, r, L, R, v, bj * 2 + 1);
  up(bj);
}
void cx(long long l, long long r, long long L, long long R, long long &v,
        long long bj) {
  if (tree[bj].minn > v) return;
  if (L <= l && r <= R) {
    if (tree[bj].value <= v)
      v -= tree[bj].value, ans += r - l + 1;
    else {
      long long mid = (l + r) / 2;
      down(l, r, mid, bj);
      cx(l, mid, L, R, v, bj * 2);
      cx(mid + 1, r, L, R, v, bj * 2 + 1);
    }
    return;
  }
  long long mid = (l + r) / 2;
  down(l, r, mid, bj);
  if (L <= mid) cx(l, mid, L, R, v, bj * 2);
  if (mid < R) cx(mid + 1, r, L, R, v, bj * 2 + 1);
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  build(1, n, 1);
  for (long long i = 1; i <= m; ++i) {
    long long type = read();
    if (type == 1) {
      long long x = read(), v = read();
      xg(1, n, 1, x, v, 1);
    } else {
      long long x = read(), v = read();
      ans = 0;
      cx(1, n, x, n, v, 1);
      printf("%lld\n", ans);
    }
  }
  return 0;
}

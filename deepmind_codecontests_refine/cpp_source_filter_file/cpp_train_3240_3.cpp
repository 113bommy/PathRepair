#include <bits/stdc++.h>
using namespace std;
const int N = 5100, p = 998244353;
int n, t, top;
long long a[N], b[N], ans, lisan[N << 1], sumg = 0;
struct node {
  int x, y;
  long long t;
} sta[N << 1];
struct EDGE {
  int l, r, h, v;
} edge[N];
struct TREE {
  int l, r, cnt;
  long long sum;
} tree[N << 2];
bool cmp(EDGE x, EDGE y) { return x.h < y.h; }
void update(int x) {
  if (tree[x].cnt)
    tree[x].sum = lisan[tree[x].r + 1] - lisan[tree[x].l];
  else {
    if (tree[x].l != tree[x].r)
      tree[x].sum = tree[(x << 1)].sum + tree[((x << 1) + 1)].sum;
    else
      tree[x].sum = 0;
  }
}
void build(int x, int l, int r) {
  tree[x].l = l, tree[x].r = r;
  tree[x].cnt = tree[x].sum = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build((x << 1), l, mid);
  build(((x << 1) + 1), mid + 1, r);
}
void change(int x, int l, int r, int v) {
  if (tree[x].l >= l && tree[x].r <= r) {
    tree[x].cnt += v;
    update(x);
    return;
  }
  int mid = (tree[x].l + tree[x].r) >> 1;
  if (l <= mid) change((x << 1), l, r, v);
  if (r > mid) change(((x << 1) + 1), l, r, v);
  update(x);
  return;
}
long long query() { return tree[1].sum; }
long long calc(long long t) {
  long long sum = 0, lash = 0, lasl = 0, nowh = 0;
  int tot = 0, num = 0;
  for (int i = 1; i <= n; i++) {
    edge[++tot].l = a[i] - t;
    edge[tot].r = a[i] + t + 1;
    edge[tot].h = b[i] - t;
    edge[tot].v = 1;
    edge[++tot].l = a[i] - t;
    edge[tot].r = a[i] + t + 1;
    edge[tot].h = b[i] + t + 1;
    edge[tot].v = -1;
    lisan[++num] = a[i] - t;
    lisan[++num] = a[i] + t + 1;
  }
  sort(lisan + 1, lisan + 1 + num);
  num = unique(lisan + 1, lisan + 1 + num) - lisan - 1;
  for (int i = 1; i <= tot; i++) {
    edge[i].l = lower_bound(lisan + 1, lisan + 1 + num, edge[i].l) - lisan;
    edge[i].r = lower_bound(lisan + 1, lisan + 1 + num, edge[i].r) - lisan;
  }
  build(1, 1, num - 1);
  sort(edge + 1, edge + 1 + tot, cmp);
  for (int i = 1; i <= tot; i++) {
    nowh = edge[i].h;
    sum = (sum + ((nowh - lash) * lasl) % p) % p;
    change(1, edge[i].l, edge[i].r - 1, edge[i].v);
    lash = edge[i].h;
    lasl = query();
  }
  return sum;
}
long long qpow(long long a, int b) {
  long long ans1 = 1;
  while (b) {
    if (b & 1) ans1 = ans1 * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans1;
}
long long work(long long x) {
  long long ans1;
  ans1 = x * (x + 1) % p * (x * 2 + 1) % p * qpow(6ll, p - 2) % p;
  return ans1;
}
long long work2(long long x) {
  long long ans1;
  ans1 = ((x * (x + 1)) / 2ll) % p;
  return ans1;
}
bool cmp2(node x, node y) { return x.t < y.t; }
int main() {
  cin >> n >> t;
  sta[0].t = 0;
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &b[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      long long tmp;
      tmp = max(abs(a[i] - a[j]), abs(b[i] - b[j]));
      tmp /= 2;
      if (tmp >= t) continue;
      sta[++top].x = i, sta[top].y = j, sta[top].t = tmp;
    }
  }
  sta[++top].t = t;
  sort(sta + 1, sta + 1 + top, cmp2);
  for (int i = 1; i <= top; i++) {
    if (sta[i].t - sta[i - 1].t <= 3) {
      for (int j = sta[i - 1].t + 1; j <= sta[i].t; j++) {
        sumg = (sumg + calc(j)) % p;
      }
    } else {
      long long tmp[5][5], a1, b1, c1;
      for (int j = sta[i - 1].t + 1; j <= sta[i - 1].t + 3; j++)
        tmp[j - sta[i - 1].t][4] = calc((long long)j),
                        tmp[j - sta[i - 1].t][3] = 1,
                        tmp[j - sta[i - 1].t][2] = j,
                        tmp[j - sta[i - 1].t][1] =
                            (long long)j * (long long)j % p;
      for (int e = 1; e <= 3; e++) {
        int l = e;
        for (int j = e + 1; j <= 3; j++)
          if (abs(tmp[j][e]) > abs(tmp[l][e])) l = j;
        if (l != e) swap(tmp[e], tmp[l]), l = i;
        long long inv;
        inv = qpow(tmp[e][e], p - 2);
        for (int j = 1; j <= 4; j++) tmp[e][j] = tmp[e][j] * inv % p;
        for (int j = 1; j <= 3; j++) {
          if (e == j) continue;
          long long o = tmp[j][e];
          for (int k = 1; k <= 4; k++) {
            tmp[j][k] -= o * tmp[e][k] % p;
            if (tmp[j][k] < 0) tmp[j][k] += p;
          }
        }
      }
      a1 = tmp[1][4] % p;
      b1 = tmp[2][4] % p;
      c1 = tmp[3][4] % p;
      long long o2 = sta[i - 1].t, o1 = sta[i].t;
      sumg += a1 * (work(o1) - work(o2)) % p +
              b1 * (work2(o1) - work2(o2)) % p + c1 * (o1 - o2) % p;
      sumg %= p;
    }
  }
  sumg += n;
  sumg -= calc(t);
  if (sumg < 0) sumg += p;
  ans = (calc(t) * t - sumg) % p;
  if (ans < 0) ans += p;
  cout << ans;
  return 0;
}

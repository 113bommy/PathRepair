#include <bits/stdc++.h>
using namespace std;
int n, m, sum[100011];
struct data {
  int id, val;
} a[100011], srt[19][100011];
struct node {
  int x;
  long long y;
  int id;
  node() {}
  node(int a, long long b, int c) {
    x = a;
    y = b;
    id = c;
  }
  inline long long plot(node a, node b) {
    return (b.y - y) * (a.x - x) - (a.y - y) * (b.x - x);
  }
} tree[19][100011];
int sz[100011 * 4];
inline int getint() {
  static char c;
  static int x;
  x = 0;
  while (c = getchar(), !isdigit(c))
    ;
  while (x = x * 10 + c - 48, c = getchar(), isdigit(c))
    ;
  return x;
}
void init() {
  n = getint();
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    a[i].val = getint();
    sum[i] = sum[i - 1] + a[i].val;
    a[i].id = i;
  }
}
inline void hb(data *a, int a_size, data *b, int b_size, data *t) {
  static int ca, cb;
  ca = cb = 0;
  while (ca + cb < a_size + b_size)
    t[ca + cb] = (ca < a_size && (cb == b_size || a[ca].val < b[cb].val))
                     ? (a[ca++])
                     : (b[cb++]);
}
inline void calc(data *a, int a_size, node *t, int &sz) {
  sz = 0;
  for (int i = 0; i < a_size; ++i) {
    node tmp =
        node(a[i].val, (long long)(a[i].val) * a[i].id - sum[a[i].id], a[i].id);
    while (sz > 1 && t[sz - 2].plot(t[sz - 1], tmp) <= 0) --sz;
    t[sz++] = tmp;
  }
}
void built(int deep, int p, int l, int r) {
  if (l == r) {
    srt[deep][l] = a[l];
    tree[deep][l] = node(a[l].val, (long long)(a[l].val) * l - sum[l], l);
    sz[p] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  built(deep + 1, p << 1, l, mid);
  built(deep + 1, (p << 1) + 1, mid + 1, r);
  hb(srt[deep + 1] + l, mid - l + 1, srt[deep + 1] + mid + 1, r - mid,
     srt[deep] + l);
  calc(srt[deep] + l, r - l + 1, tree[deep] + l, sz[p]);
}
struct data2 {
  int x, y, id;
} qst[100011];
inline bool operator<(const data2 &a, const data2 &b) {
  if (b.y - b.x < a.y - a.x) return 1;
  return 0;
}
void quest() {
  m = getint();
  for (int i = 0; i < m; ++i) {
    qst[i].x = getint(), qst[i].y = getint();
    qst[i].id = i;
  }
  sort(qst, qst + m);
}
long long ans[100011];
inline long long calc(int x, int y_x) {
  return (a[x].val * (x - y_x)) - sum[x];
}
int aa, bb;
int t;
long long ask(int deep, int p, int l, int r) {
  long long res = 2147483647;
  if (aa < l && r <= bb) {
    while (sz[p] > 1 &&
           (tree[deep][l + sz[p] - 1].y - tree[deep][l + sz[p] - 2].y) >=
               (tree[deep][l + sz[p] - 1].x - tree[deep][l + sz[p] - 2].x) * aa)
      --sz[p];
    return calc(tree[deep][l + sz[p] - 1].id, aa);
  }
  int mid = (l + r) >> 1;
  if (aa < mid) {
    t = ask(deep + 1, p * 2, l, mid);
    res = ((res) < (t) ? (res) : (t));
  }
  if (mid < bb) {
    t = ask(deep + 1, p * 2 + 1, mid + 1, r);
    res = ((res) < (t) ? (res) : (t));
  }
  return res;
}
void print() {
  for (int i = 0; i < m; ++i) {
    aa = qst[i].y - qst[i].x;
    bb = qst[i].y;
    ans[qst[i].id] = ask(0, 1, 1, n) + sum[qst[i].y];
  }
  for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
}
int main() {
  init();
  built(0, 1, 1, n);
  quest();
  print();
  return 0;
}

#include <bits/stdc++.h>
const int MOD = 1000000007;
const int INF = 21000001;
const double EPS = 1e-6;
const int HASH_POW = 29;
const double PI = acos(-1.0);
using namespace std;
int n, q;
struct node {
  int p[5][5];
} t[800010];
char s[200010];
void merge(node &a, node &b, node &c) {
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j) c.p[i][j] = INF;
  for (int i = 0; i < 5; ++i) {
    for (int j = i; j < 5; ++j) {
      for (int k = i; k <= j; ++k)
        c.p[i][j] = min(c.p[i][j], a.p[i][k] + b.p[k][j]);
    }
  }
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j) t[v].p[i][j] = INF;
    for (int i = 0; i < 5; ++i) t[v].p[i][i] = 0;
    if (s[tl] == '2') {
      t[v].p[0][0] = 1;
      t[v].p[0][1] = 0;
    } else if (s[tl] == '0') {
      t[v].p[1][1] = 1;
      t[v].p[1][2] = 0;
    } else if (s[tl] == '1') {
      t[v].p[2][2] = 1;
      t[v].p[2][3] = 0;
    } else if (s[tl] == '6') {
      t[v].p[3][3] = 1;
      t[v].p[4][4] = 0;
    } else if (s[tl] == '7') {
      t[v].p[3][4] = 0;
    }
  } else {
    int mid = ((tl + tr) >> 1);
    build((v << 1), tl, mid);
    build((v << 1) + 1, mid + 1, tr);
    merge(t[(v << 1)], t[(v << 1) + 1], t[v]);
  }
}
node query(int v, int tl, int tr, int l, int r) {
  if (l > r || tl > r || tr < l) {
    node res;
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j) res.p[i][j] = 0;
    return res;
  }
  int mid = ((tl + tr) >> 1);
  node a, b, ret;
  if (tl >= l && tr <= r)
    ret = t[v];
  else {
    a = query((v << 1), tl, mid, l, r);
    b = query((v << 1) + 1, mid + 1, tr, l, r);
    merge(a, b, ret);
    if (r <= mid) return a;
    if (l > mid) return b;
  }
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
    }
  return ret;
}
int main() {
  scanf("%d %d\n%s", &n, &q, s + 1);
  build(1, 1, n);
  while (q-- > 0) {
    int l, r;
    scanf("%d %d", &l, &r);
    int res = query(1, 1, n, l, r).p[0][4];
    if (res == INF)
      printf("-1\n");
    else
      printf("%d\n", res);
  }
  return 0;
}

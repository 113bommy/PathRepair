#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int MAXF = 10020;
int n, k;
struct node {
  int r, x, f;
  bool operator<(const node &a) const { return r > a.r; }
} it[MAXN];
struct dat {
  int op, x, y, w;
  bool operator<(const dat &a) const {
    if (x == a.x) return op < a.op;
    return x < a.x;
  }
} Q[MAXN * 5], t[MAXN * 5];
int cnt = 0;
inline int lowbit(int num) { return num & -num; }
int c[MAXF] = {0};
void add(int x, int v) {
  for (; x <= MAXF - 1; x += lowbit(x)) c[x] += v;
}
int query(int x) {
  int sum = 0;
  for (; x; x -= lowbit(x)) sum += c[x];
  return sum;
}
void clear(int x) {
  for (; x <= MAXF - 1; x += lowbit(x)) c[x] = 0;
}
long long ans = 0;
void cdq(int L, int R) {
  if (R - L <= 1) return;
  int M = (L + R) >> 1;
  cdq(L, M);
  cdq(M, R);
  int p = L, q = M, o = L;
  while (p < M && q < R) {
    if (Q[p] < Q[q]) {
      if (Q[p].op == 0) add(Q[p].y, 1);
      t[o++] = Q[p++];
    } else {
      if (Q[q].op == 1) ans += query(Q[q].y) * Q[q].w;
      t[o++] = Q[q++];
    }
  }
  while (p < M) t[o++] = Q[p++];
  while (q < R) {
    if (Q[q].op == 1) ans += query(Q[q].y) * Q[q].w;
    t[o++] = Q[q++];
  }
  for (int i = L; i < R; ++i) {
    if (Q[i].op == 0) clear(Q[i].y);
    Q[i] = t[i];
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d%d%d", &it[i].x, &it[i].r, &it[i].f);
  sort(it, it + n);
  for (int i = 0; i < n; ++i) {
    node &T = it[i];
    int x1 = T.x - T.r, y1 = max(T.f - k, 1);
    int x2 = T.x + T.r, y2 = T.f + k;
    Q[cnt++] = (dat){1, x1 - 1, y1 - 1, 1};
    Q[cnt++] = (dat){1, x1 - 1, y2, -1};
    Q[cnt++] = (dat){1, x2, y1 - 1, -1};
    Q[cnt++] = (dat){1, x2, y2, 1};
    Q[cnt++] = (dat){0, T.x, T.f, 0};
  }
  cdq(0, cnt);
  cout << ans << endl;
  return 0;
}

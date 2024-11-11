#include <bits/stdc++.h>
using namespace std;
int n, Ans = 1, ans1, ans2;
int to[100005 * 2], nxt[100005 * 2], fst[100005], val[100005 * 2],
    col[100005 * 2], l = 1, e[100005 * 2];
int Rt[100005], cnt, ls[10000005], rs[10000005], sum[10000005], sz[10000005];
int size[100005], Mx[100005], s[100005][2], r[100005];
int d[100005], ly;
void link(int x, int y, int v, int c) {
  to[++l] = y;
  e[l] = 1;
  val[l] = v;
  col[l] = c;
  nxt[l] = fst[x];
  fst[x] = l;
  to[++l] = x;
  e[l] = 1;
  val[l] = v;
  col[l] = c;
  nxt[l] = fst[y];
  fst[y] = l;
}
void dfs(int x, int f) {
  size[x] = 1;
  Mx[x] = 0;
  for (int i = fst[x]; i; i = nxt[i])
    if (to[i] != f && e[i]) {
      dfs(to[i], x);
      size[x] += size[to[i]];
      Mx[x] = max(Mx[x], size[to[i]]);
    }
}
void Get(int x, int &g, int f, int sz) {
  Mx[x] = max(sz - size[x], Mx[x]);
  if (Mx[x] < Mx[g]) g = x;
  for (int i = fst[x]; i; i = nxt[i])
    if (to[i] != f && e[i]) Get(to[i], g, x, sz);
}
void add(int x, int f) {
  for (int i = fst[x]; i; i = nxt[i])
    if (to[i] != f && e[i]) {
      d[++ly] = to[i];
      s[to[i]][0] = s[x][0];
      s[to[i]][1] = s[x][1];
      s[to[i]][col[i]]++;
      r[to[i]] = (long long)r[x] * val[i] % 1000000007;
      add(to[i], x);
    }
}
int nd(int k) {
  cnt++;
  sz[cnt] = sz[k];
  sum[cnt] = sum[k];
  ls[cnt] = ls[k];
  rs[cnt] = rs[k];
  return cnt;
}
void mdy(int p, int &q, int l, int r, int x, int y) {
  q = nd(p);
  sz[q] = sz[q] + 1;
  sum[q] = (long long)sum[q] * y % 1000000007;
  if (l == r) return;
  int mid = l + (r - l) / 2;
  if (x <= mid)
    mdy(ls[p], ls[q], l, mid, x, y);
  else
    mdy(rs[p], rs[q], mid + 1, r, x, y);
}
void qry(int k, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    ans1 = (long long)ans1 * sum[k] % 1000000007;
    ans2 = ans2 + sz[k];
    return;
  }
  int mid = l + (r - l) / 2, ans = 1;
  if (x <= mid) qry(ls[k], l, mid, x, y);
  if (y > mid) qry(rs[k], mid + 1, r, x, y);
}
bool cmp(int x, int y) {
  return (2 * s[x][0] - s[x][1] != 2 * s[y][0] - s[y][1])
             ? (2 * s[x][0] - s[x][1] > 2 * s[y][0] - s[y][1])
             : (2 * s[x][1] - s[x][0] > 2 * s[y][1] - s[y][0]);
}
int L, R;
int find(int x) {
  int l = 1, r = ly, mid, ans = 0;
  while (l <= r) {
    mid = l + r >> 1;
    if (2 * s[d[mid]][0] - s[d[mid]][1] >= x)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
int pw(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % 1000000007)
    if (y & 1) ans = (long long)ans * x % 1000000007;
  return ans;
}
int inv(int x) { return pw(x, 1000000007 - 2); }
int add(int x) {
  int ans = 1;
  ly = 0;
  cnt = 0;
  add(x, 0);
  sort(d + 1, d + ly + 1, cmp);
  L = -ly;
  R = ly * 2;
  for (int i = 1; i <= ly; i++) {
    ans1 = 1;
    ans2 = 0;
    qry(Rt[min(find(s[d[i]][1] - 2 * s[d[i]][0]), i - 1)], L, R,
        s[d[i]][0] - 2 * s[d[i]][1], R);
    ans = (long long)ans * pw(r[d[i]], ans2) % 1000000007 * ans1 % 1000000007;
    mdy(Rt[i - 1], Rt[i], L, R, 2 * s[d[i]][1] - s[d[i]][0], r[d[i]]);
  }
  ans1 = 1;
  ans2 = 0;
  qry(Rt[find(s[x][1] - 2 * s[x][0])], L, R, s[x][0] - 2 * s[x][1], R);
  ans = (long long)ans * pw(r[x], ans2) % 1000000007 * ans1 % 1000000007;
  return ans;
}
void work(int x) {
  int g = x;
  dfs(x, 0);
  Get(x, g, 0, size[x]);
  s[g][0] = s[g][1] = 0;
  r[g] = 1;
  int ans = add(g);
  for (int i = fst[g]; i; i = nxt[i])
    if (e[i]) {
      e[i] = e[i ^ 1] = 0;
      ans = (long long)ans * inv(add(to[i])) % 1000000007;
      work(to[i]);
    }
  Ans = (long long)Ans * ans % 1000000007;
}
int main() {
  scanf("%d", &n);
  sum[0] = 1;
  for (int i = 1; i < n; i++) {
    int x, y, v, c;
    scanf("%d%d%d%d", &x, &y, &v, &c);
    link(x, y, v, c);
  }
  work(1);
  printf("%d\n", Ans);
}

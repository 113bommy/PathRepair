#include <bits/stdc++.h>
using namespace std;
const int N = 400005, M = 10000000;
long long sum[M], val[M], fsum[N];
int node[N], siz[M], son[M][2];
int e[N], a[N], b[N], aset[N];
long long n, c, cnt;
int finds(int x) { return x == aset[x] ? x : aset[x] = finds(aset[x]); }
void pushup(int nde) {
  int ls = son[nde][0], rs = son[nde][1];
  sum[nde] = sum[ls] + sum[rs], siz[nde] = siz[ls] + siz[rs];
  val[nde] = val[ls] + val[rs] + 1ll * sum[ls] * siz[rs];
}
void Create(int &nde, int l, int r, int pos, int task) {
  if (!nde) nde = ++cnt;
  if (l == r)
    siz[nde] = 1, sum[nde] = val[nde] = task;
  else {
    int mid = (l + r) / 2;
    if (pos <= mid)
      Create(son[nde][0], l, mid, pos, task);
    else
      Create(son[nde][1], mid + 1, r, pos, task);
    pushup(nde);
  }
}
int Merge(int x, int y) {
  if (!x || !y) return x | y;
  int tmp = x;
  son[tmp][0] = Merge(son[x][0], son[y][0]);
  son[tmp][1] = Merge(son[x][1], son[y][1]);
  if (!son[tmp][0] && !son[tmp][1]) {
    val[tmp] = val[x] + val[y] + 1ll * sum[y] * siz[x];
    sum[tmp] = sum[x] + sum[y];
    siz[tmp] = siz[x] + siz[y];
  } else
    pushup(tmp);
  return tmp;
}
long long query(int nde) {
  int nd = node[nde];
  return val[nd] + 1ll * (nde - 1) * sum[nd];
}
void gather(int a, int b) {
  int f1 = finds(a), f2 = finds(b);
  aset[f2] = f1, c -= query(f1), c -= query(f2);
  node[f1] = Merge(node[f1], node[f2]), c += query(f1);
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= 400000; i++) aset[i] = i;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    fsum[i] = fsum[i - 1] + a[i] * b[i];
    a[i] = finds(a[i]), aset[a[i]] = a[i] + 1;
    Create(node[a[i]], 1, 400000, b[i], b[i]);
  }
  for (int i = 1; i <= 400000; i++) aset[i] = i;
  for (int i = 1; i <= n; i++) {
    c += query(a[i]);
    if (e[a[i] + 1]) gather(a[i], a[i] + 1);
    if (e[a[i] - 1]) gather(a[i] - 1, a[i]);
    e[a[i]] = true, printf("%lld\n", c - fsum[i]);
  }
  return 0;
}

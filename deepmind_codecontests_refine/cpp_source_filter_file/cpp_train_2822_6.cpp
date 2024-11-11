#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int mod = (int)1e9 + 7;
const int up = (int)1e9;
int n, k, cnt;
struct node {
  int x, r, q;
} e[maxn];
bool cmp(node a, node b) { a.r > b.r; }
map<int, int> root;
int num[maxn * 35], lson[maxn * 35], rson[maxn * 35];
long long ans = 0;
void build(int pos, int l, int r, int &rt) {
  if (!rt) rt = ++cnt;
  num[rt]++;
  if (l == r) return;
  int mid = (l + r) / 2;
  if (pos <= mid)
    build(pos, l, mid, lson[rt]);
  else
    build(pos, mid + 1, r, rson[rt]);
}
long long query(int ql, int qr, int l, int r, int rt) {
  if (!rt) return 0;
  if (ql <= l && r <= qr) {
    return (long long)num[rt];
  }
  int mid = (l + r) / 2;
  long long tans = 0;
  if (ql <= mid) tans += query(ql, qr, l, mid, lson[rt]);
  if (qr > mid) tans += query(ql, qr, mid + 1, r, rson[rt]);
  return tans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d%d", &e[i].x, &e[i].r, &e[i].q);
  sort(e + 1, e + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = e[i].q - k; j <= e[i].q + k; j++) {
      ans = (ans + query(e[i].x - e[i].r, e[i].x + e[i].r, 0, up, root[j]));
    }
    build(e[i].x, 0, up, root[e[i].q]);
  }
  printf("%lld\n", ans);
  return 0;
}

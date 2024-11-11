#include <bits/stdc++.h>
using namespace std;
int n, a[100010], maxi[100010][20];
long long ans;
struct node {
  node *ch[2];
  node() { ch[0] = ch[1] = NULL; }
} * L, *R;
int MAX(int x, int y) { return a[x] > a[y] ? x : y; }
void insert(node *(&o), int x, int k) {
  if (o == NULL) o = new node;
  if (!k) return;
  insert(o->ch[!!(x & k)], x, k >> 1);
}
long long find(node *o, int x, int k) {
  if (o == NULL) return 0;
  bool t((x & k));
  if (o->ch[t ^ 1])
    return k | find(o->ch[t ^ 1], x, k >> 1);
  else
    return find(o->ch[t], x, k >> 1);
}
long long find(int L, int R) {
  int k(0), len(1);
  while ((len << 1) < (R - L + 1)) k++, len <<= 1;
  return MAX(maxi[L][k], maxi[R - len + 1][k]);
}
void work(int L, int R, node *(&l), node *(&r)) {
  if (R < L) return;
  int o = find(L, R);
  node *r1(NULL), *l2(NULL);
  work(L, o - 1, l, r1);
  work(o + 1, R, l2, r);
  ans = max(max(find(r1, a[o], 1 << 30), find(l2, a[o], 1 << 30)), ans);
  insert(l, a[o], 1 << 30);
  insert(r, a[o], 1 << 30);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) maxi[i][0] = i;
  for (int k = 0, l = 1; (l << 1) <= n; l <<= 1, k++)
    for (int i = 1; i + (l << 1) - 1 <= n; i++)
      maxi[i][k + 1] = MAX(maxi[i][k], maxi[i + l][k]);
  work(1, n, L, R);
  printf("%lld", ans);
  return 0;
}

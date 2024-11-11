#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} a[200005];
int n;
long long ans = 0;
int v[200005], top = 0;
const int N = 200005;
int tree[200006 << 2];
void modify(int x, int k) {
  for (x += N; x; x >>= 1) tree[x] += k;
}
int query(int l, int r) {
  if (l > r) return 0;
  int ans = 0;
  for (l = N + l - 1, r = N + r + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) ans += tree[l ^ 1];
    if (r & 1) ans += tree[r ^ 1];
  }
  return ans;
}
bool cmp1(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) {
  if (a.y > b.y) return 1;
  if (a.y < b.y) return 0;
  return (a.x < b.x);
}
long long fun(int x) {
  long long r = x;
  r = x * (x + 1) / 2;
  return r;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
  sort(a + 1, a + n + 1, cmp1);
  int cnt = 1;
  int lst = a[1].x;
  a[1].x = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i].x == lst)
      a[i].x = cnt;
    else {
      lst = a[i].x;
      a[i].x = ++cnt;
    }
  }
  sort(a + 1, a + n + 1, cmp2);
  for (int i = 1; i <= n;) {
    int ty = a[i].y;
    top = 0;
    while (a[i].y == ty) v[top++] = a[i++].x;
    for (int j = 0; j < top; ++j) modify(v[j], 1 - query(v[j], v[j]));
    v[top++] = n + 1;
    ans += fun(tree[1]);
    for (int j = 0; j < top - 1; ++j) ans -= fun(query(v[j] + 1, v[j + 1] - 1));
    ans -= fun(query(1, v[0] - 1));
  }
  cout << ans << endl;
}

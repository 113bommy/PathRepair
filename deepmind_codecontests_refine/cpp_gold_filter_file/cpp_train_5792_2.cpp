#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, a[N], ans, Stack[N], tot, fa[N];
long long sum[N];
pair<int, int> b[N];
struct Tree {
  int l, r;
  long long num;
} T[N * 4];
void build(int x, int l, int r) {
  T[x].l = l;
  T[x].r = r;
  if (l == r) {
    T[x].num = sum[l];
    return;
  }
  int mid = (l + r) / 2;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
  T[x].num = T[x * 2].num + T[x * 2 + 1].num;
}
void insert(int x, int y) {
  if (T[x].l == T[x].r) {
    T[x].num = sum[T[x].l];
    return;
  }
  int mid = (T[x].l + T[x].r) / 2;
  if (y <= mid)
    insert(x * 2, y);
  else
    insert(x * 2 + 1, y);
  T[x].num = T[x * 2].num + T[x * 2 + 1].num;
}
long long find(int x, int l, int r) {
  if (T[x].l > r || l > T[x].r) return 0;
  if (T[x].l >= l && T[x].r <= r) return T[x].num;
  return find(x * 2, l, r) + find(x * 2 + 1, l, r);
}
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i].second);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i].first);
  for (int i = n; i; i--) {
    if (a[i] > a[Stack[tot]]) {
      Stack[++tot] = i;
      sum[tot] = a[i];
    } else
      sum[tot] += a[i];
  }
  reverse(Stack + 1, Stack + tot + 1);
  reverse(sum + 1, sum + tot + 1);
  build(1, 1, tot);
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int l = 0, r = tot;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (a[Stack[mid]] < b[i].second)
        r = mid - 1;
      else
        l = mid;
    }
    if (find(1, 1, l) < b[i].first)
      continue;
    else {
      int t = find(l);
      while (b[i].first) {
        long long c = min(sum[t], (long long)b[i].first);
        sum[t] -= c;
        b[i].first -= c;
        if (!sum[t]) fa[t] = t - 1;
        insert(1, t);
        t = find(t);
      }
      ans++;
    }
  }
  printf("%d\n", ans);
}

#include <bits/stdc++.h>
int n, ans[100005];
struct node {
  int x, y, col, ind;
} a[200005], C;
inline bool cmp(const node &A, const node &B) {
  return (A.y - C.y) * (B.x - C.x) < (A.x - C.x) * (B.y - C.y);
}
void Sort(int l, int r) {
  int first = 0;
  for (int i = l; i <= r; ++i)
    if (!first || (a[i].x < a[first].x) ||
        (a[i].x == a[first].x && a[i].y < a[first].y))
      first = i;
  std::swap(a[l], a[first]);
  C = a[l];
  std::sort(a + l + 1, a + r + 1, cmp);
}
void Solve(int l, int r) {
  if (l >= r) return;
  Sort(l, r);
  int sum = 0, mid = 0;
  for (int i = l; i <= r; ++i) {
    sum += a[i].col;
    if (a[i].col != a[l].col && !sum) {
      mid = i;
      break;
    }
  }
  if (a[l].col == 1)
    ans[a[l].ind] = a[mid].ind;
  else
    ans[a[mid].ind] = a[l].ind;
  Solve(l + 1, mid - 1);
  Solve(mid + 1, r);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i].x, &a[i].y), a[i].col = 1, a[i].ind = i;
  for (int i = n + 1; i <= n << 1; ++i)
    scanf("%d%d", &a[i].x, &a[i].y), a[i].col = -1, a[i].ind = i - n;
  Solve(1, n << 1);
  for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
}

#include <bits/stdc++.h>
using std::sort;
using std::swap;
using std::unique;
const int N = 300010;
int n, q, a[N], pos[N], sum[N];
void Add(int p, int v) {
  for (; p < n; p += (p & -p)) sum[p] += v;
}
int Ask(int p) {
  int res = 0;
  for (; p > 0; p -= (p & -p)) res += sum[p];
  return res;
}
void Init() { memset(sum, 0, sizeof(sum)); }
void GetData() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  scanf("%d", &q);
}
void Update(int x) {
  if (x == 0 || x == n) return;
  if (pos[x] < pos[x + 1]) {
    if (Ask(x) - Ask(x - 1) == 1) Add(x, -1);
  } else {
    if (Ask(x) - Ask(x - 1) == 0) Add(x, 1);
  }
}
void Solve() {
  int i, tp, x, y, len, ar[6];
  for (i = 1; i < n; ++i) {
    if (pos[i] > pos[i + 1]) Add(i, 1);
  }
  while (q--) {
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1)
      printf("%d\n", Ask(y - 1) - Ask(x - 1) + 1);
    else {
      pos[a[x]] = y;
      pos[a[y]] = x;
      swap(a[x], a[y]);
      for (i = -1, len = 0; i <= 1; ++i) {
        ar[len++] = x + i;
        ar[len++] = y + i;
      }
      sort(ar, ar + len);
      len = unique(ar, ar + len) - ar;
      for (i = 0; i < len; ++i) Update(ar[i]);
    }
  }
}
int main() {
  Init();
  GetData();
  Solve();
  return 0;
}

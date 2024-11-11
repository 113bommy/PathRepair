#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 300005;
int n, top, cnt;
int q[N], a[N];
pair<int, int> ans[M];
void ins(int x, int y) {
  assert(a[x] <= a[y]);
  ans[++cnt] = pair<int, int>(x, y);
  a[y] -= a[x];
  a[x] *= 2;
}
void solve(int &x, int &y, int &z) {
  for (;;) {
    if (a[x] > a[y]) swap(x, y);
    if (a[x] > a[z]) swap(x, z);
    if (a[y] > a[z]) swap(y, z);
    if (!a[x]) break;
    int v = a[y] / a[x];
    for (int vv = 1; vv <= v; vv <<= 1) v &vv ? ins(x, y) : ins(x, z);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (a[i]) q[++top] = i;
  if (top <= 1) return puts("-1"), 0;
  for (; top >= 3; --top) solve(q[top], q[top - 1], q[top - 2]);
  printf("%d\n", cnt);
  for (int i = (int)(1); i <= (int)(cnt); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
}

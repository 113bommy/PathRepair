#include <bits/stdc++.h>
using namespace std;
const int MAXA = 4e5;
int n;
int tr[MAXA << 2], a[MAXA];
queue<int> q[MAXA];
int build(int x, int l, int r) {
  if (l == r) return tr[x] = a[l];
  int mid = (l + r) >> 1;
  return tr[x] = max(build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r));
}
int ask(int x, int l, int r, int val) {
  if (r <= val) return tr[x];
  int mid = (l + r) >> 1;
  if (val <= mid) return ask(x << 1, l, mid, val);
  return max(tr[x << 1], ask(x << 1 | 1, mid + 1, r, val));
}
int change(int x, int l, int r, int val) {
  if (l == r) return tr[x] = n + 1;
  int mid = (l + r) >> 1;
  if (val <= mid)
    change(x << 1, l, mid, val);
  else
    change(x << 1 | 1, mid + 1, r, val);
  return tr[x] = min(tr[x << 1], tr[x << 1 | 1]);
}
int solve() {
  int x, y, flag = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    q[a[i]].push(i);
  }
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (q[x].empty()) {
      flag = 0;
      continue;
    }
    y = q[x].front();
    if (y > 1 && ask(1, 1, n, y - 1) < x) {
      flag = 0;
    }
    change(1, 1, n, y);
    q[x].pop();
  }
  for (int i = 1; i <= n; i++)
    while (!q[a[i]].empty()) q[a[i]].pop();
  return flag;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    if (solve())
      printf("YES\n");
    else
      printf("NO\n");
  }
}

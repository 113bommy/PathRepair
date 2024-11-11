#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
const int maxn = 3e5 + 5;
queue<int> q[maxn];
int tr[maxn * 5], a[maxn], b[maxn];
int init(int l, int r, int p) {
  if (l == r) {
    return tr[p] = q[l].front();
  }
  int mid = (l + r) >> 1;
  return tr[p] = min(init(l, mid, p * 2), init(mid + 1, r, p * 2 + 1));
}
int ask(int x, int y, int p, int l, int r) {
  if (x <= l && r <= y) {
    return tr[p];
  }
  int mid = (l + r) >> 1;
  int res = inf;
  if (x <= mid) res = min(res, ask(x, y, p * 2, l, mid));
  if (y > mid) res = min(res, ask(x, y, p * 2 + 1, mid + 1, r));
  return res;
}
int chg(int x, int p, int l, int r) {
  if (l == r) {
    return tr[p] = q[l].front();
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    chg(x, p * 2, l, mid);
  else
    chg(x, p * 2 + 1, mid + 1, r);
  tr[p] = min(tr[p * 2], tr[p * 2 + 1]);
}
void run() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    while (!q[i].empty()) {
      q[i].pop();
    }
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    q[a[i]].push(i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    q[i].push(n + 1);
  }
  init(1, n, 1);
  a[n + 1] = inf;
  for (int i = 1; i <= n; ++i) {
    if (q[b[i]].front() == n + 1) {
      puts("NO");
      return;
    }
    int t = ask(1, a[i], 1, 1, n);
    if (a[t] < b[i]) {
      puts("NO");
      return;
    } else {
      q[b[i]].pop();
      chg(b[i], 1, 1, n);
    }
  }
  puts("YES");
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  scanf("%d", &T);
  while (T--) {
    run();
  }
  return 0;
}

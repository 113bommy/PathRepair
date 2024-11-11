#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 4000 + 10, M = 20000 + 10;
int n, p, Q, ans[M];
int dp[N], sta[16][N], top = 0;
vector<pair<int, int> > t[M << 2], q[M << 2];
void modify(int o, int l, int r, int ql, int qr, int op, int a, int b) {
  if (ql <= l && r <= qr) {
    if (!op)
      t[o].push_back(make_pair(a, b));
    else
      q[o].push_back(make_pair(a, b));
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) modify((o << 1), l, mid, ql, qr, op, a, b);
  if (qr > mid) modify((o << 1 | 1), mid + 1, r, ql, qr, op, a, b);
}
void solve(int o, int l, int r) {
  ++top;
  for (int i = 1; i <= 4000; ++i) sta[top][i] = dp[i];
  for (auto i : t[o]) {
    int c = i.first, h = i.second;
    for (int j = 4000; j >= c; --j) dp[j] = max(dp[j], dp[j - c] + h);
  }
  if (l == r) {
    for (auto i : q[o]) ans[i.first] = dp[i.second];
  } else {
    int mid = (l + r) >> 1;
    solve((o << 1), l, mid), solve((o << 1 | 1), mid + 1, r);
  }
  for (int i = 1; i <= 4000; ++i) dp[i] = sta[top][i];
  --top;
}
int main() {
  n = read(), p = read();
  for (int i = 1; i <= n; ++i) {
    int c = read(), h = read(), t = read();
    modify(1, 1, 20000, t, t + p - 1, 0, c, h);
  }
  Q = read();
  for (int i = 1; i <= Q; ++i) {
    int a = read(), b = read();
    modify(1, 1, 20000, a, a, 1, i, b);
  }
  solve(1, 1, 20000);
  for (int i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
  return 0;
}

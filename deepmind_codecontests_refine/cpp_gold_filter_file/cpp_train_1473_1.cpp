#include <bits/stdc++.h>
using namespace std;
const int N = 1E6 + 10;
const int inf = 1 << 30;
long long read() {
  long long a = 0;
  char b = 1, c;
  do
    if ((c = getchar()) == 45) b = -1;
  while (c < 48 || c > 57);
  do a = (a << 3) + (a << 1) + (c & 15);
  while ((c = getchar()) > 47 && c < 58);
  return a * b;
}
void write(long long x, char c) {
  if (x < 0) putchar(45), x = -x;
  char a[20], s = 0;
  do a[++s] = x % 10 | 48;
  while (x /= 10);
  do putchar(a[s]);
  while (--s);
  putchar(c);
}
int n, m;
int a[N], u[N], v[N];
int head[N], nex[N], to[N], cnt;
pair<int, int> q[N];
long long ans[N];
int l[N << 2], r[N << 2], laz[N << 2];
long long sum[N << 2];
void addedge(int u, int v) {
  nex[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
void dt(int i, int val) {
  sum[i] += (r[i] - l[i] + 1) * 1LL * val;
  laz[i] += val;
}
void push_down(int i) {
  if (!laz[i]) return;
  dt(i << 1, laz[i]);
  dt(i << 1 | 1, laz[i]);
  laz[i] = 0;
}
void build(int i, int L, int R) {
  l[i] = L;
  r[i] = R;
  if (L == R) return;
  int M = L + R >> 1;
  build(i << 1, L, M);
  build(i << 1 | 1, M + 1, R);
}
void cha(int i, int L, int R) {
  if (l[i] > R || r[i] < L) return;
  if (l[i] >= L && r[i] <= R)
    dt(i, 1);
  else {
    push_down(i);
    cha(i << 1, L, R);
    cha(i << 1 | 1, L, R);
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
  }
}
long long ask(int i, int L, int R) {
  if (l[i] > R || r[i] < L) return 0;
  if (l[i] >= L && r[i] <= R) return sum[i];
  push_down(i);
  return ask(i << 1, L, R) + ask(i << 1 | 1, L, R);
}
void solve() {
  for (int i = 1; i <= m; ++i) addedge(v[i], i);
  for (int i = 1, s = 0; i <= n; ++i) {
    pair<int, int> y = make_pair(i, i);
    while (a[q[s].second] < a[i]) {
      cha(1, q[s].first, q[s].second);
      y.first = q[s].first;
      --s;
    }
    q[++s] = y;
    for (int j = head[i]; j; j = nex[j]) {
      int t = to[j];
      ans[t] += ask(1, u[t], i);
    }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= m; ++i) u[i] = read();
  for (int i = 1; i <= m; ++i) v[i] = read();
  a[0] = inf;
  build(1, 1, n);
  solve();
  reverse(a + 1, a + 1 + n);
  memset(head + 1, 0, n << 2);
  memset(sum, 0, sizeof sum);
  memset(laz, 0, sizeof laz);
  cnt = 0;
  for (int i = 1; i <= m; ++i) {
    int t = n + 1 - u[i];
    u[i] = n + 1 - v[i];
    v[i] = t;
  }
  solve();
  for (int i = 1; i <= m; ++i) {
    write(ans[i] + v[i] - u[i] + 1, ' ');
  }
}

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
long long ans[N], _l[N], _r[N];
void addedge(int u, int v) {
  nex[++cnt] = head[u];
  head[u] = cnt;
  to[cnt] = v;
}
void push(long long *a, int x, int val) {
  while (x <= n) {
    a[x] += val;
    x += x & -x;
  }
}
void add(int l, int r) {
  ++r;
  push(_l, l, 1);
  push(_l, r, -1);
  push(_r, l, l);
  push(_r, r, -r);
}
long long pre(long long *a, int x) {
  long long res = 0;
  while (x) {
    res += a[x];
    x -= x & -x;
  }
  return res;
}
long long ask(int l, int r) {
  return pre(_l, r) * (r + 1) - pre(_r, r) - pre(_l, l - 1) * l +
         pre(_r, l - 1);
}
void solve() {
  for (int i = 1; i <= m; ++i) addedge(v[i], i);
  for (int i = 1, s = 0; i <= n; ++i) {
    pair<int, int> y = make_pair(i, i);
    while (a[q[s].second] < a[i]) {
      add(q[s].first, q[s].second);
      y.first = q[s].first;
      --s;
    }
    q[++s] = y;
    for (int j = head[i]; j; j = nex[j]) {
      int t = to[j];
      ans[t] += ask(u[t], i);
    }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= m; ++i) u[i] = read();
  for (int i = 1; i <= m; ++i) v[i] = read();
  a[0] = inf;
  solve();
  reverse(a + 1, a + 1 + n);
  memset(head + 1, 0, n << 2);
  memset(_l + 1, 0, n << 3);
  memset(_r + 1, 0, n << 3);
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

#include <bits/stdc++.h>
using namespace std;
const int N = 5005, M = 1e5 + 5;
struct E {
  int from, to, dis, id;
  inline friend bool operator<(E a, E b) {
    return a.dis == b.dis ? a.from > b.from : a.dis < b.dis;
  }
} e[M], t[M];
int n, m, s, f[N], res[N], cnt, now;
inline int read() {
  int x = 0, w = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') c = getchar(), w = -1;
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * w;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline bool check(int k) {
  memcpy(e, t, sizeof(t));
  for (register int i = 1; i <= n; i++) f[i] = i;
  for (register int i = 1; i <= m; i++) e[i].dis += (e[i].from == 1 ? k : 0);
  sort(e + 1, e + m + 1);
  cnt = now = 0;
  for (register int i = 1; i <= m; i++) {
    int u = find(e[i].from), v = find(e[i].to);
    if (u == v || (now == s && e[i].from == 1)) continue;
    f[u] = v;
    now += (e[i].from == 1);
    res[++cnt] = e[i].id;
    if (cnt == n - 1) break;
  }
  return now >= s;
}
int main() {
  n = read(), m = read(), s = read();
  for (register int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    if (x > y) swap(x, y);
    t[i] = (E){x, y, z, i};
  }
  int l = -M, r = M, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  check(ans);
  if (cnt != n - 1 || now < s)
    puts("-1");
  else {
    printf("%d\n", cnt);
    for (register int i = 1; i <= cnt; i++) printf("%d ", res[i]);
  }
  return 0;
}

#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f * x;
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
void umax(long long& a, long long t) {
  if (t > a) a = t;
}
bool umin(long long& a, long long t) {
  if (t < a) return a = t, 1;
  return 0;
}
int cnt[1000011];
struct DSU {
  int fa[1000011], size[1000011];
  void build(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i, size[i] = 1;
  }
  int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
  }
  int uni(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (size[x] > size[y]) std::swap(x, y);
    int t = cnt[x] + cnt[y] - 1;
    fa[x] = y, cnt[y] = 1, size[y] += size[x];
    return t;
  }
} st;
int main() {
  int n = read(), x;
  long long ans = 0;
  st.build((1 << 18) - 1);
  cnt[0] = 1;
  for (int i = 1; i <= n; ++i) x = read(), ++cnt[x], ans -= x;
  for (int s = (1 << 18) - 1; s >= 0; --s)
    for (int t = s;; t = (t - 1) & s) {
      if (cnt[s ^ t] && cnt[t]) ans += s * st.uni(s ^ t, t);
      if (!t) break;
    }
  printf("%lld", ans);
  return 0;
}

#include <bits/stdc++.h>
inline int rd() {
  int x = 0, p = 1;
  char a = getchar();
  while ((a < 48 || a > 57) && a != '-') a = getchar();
  if (a == '-') p = -p, a = getchar();
  while (a > 47 && a < 58) x = (x << 1) + (x << 3) + (a & 15), a = getchar();
  return x * p;
}
const int N = 500002;
int n, m;
struct node {
  int s, t, k, id;
  node(int S = 0, int T = 0, int K = 0, int Id = 0) {
    s = S, t = T, k = K, id = Id;
  }
  bool operator<(const node &y) const { return t < y.t; }
} a[N], b[N];
int ans[N];
std::set<std::pair<int, int> > s;
int main() {
  n = rd();
  for (int i = 1; i <= n; i++) {
    a[i].s = rd(), a[i].t = rd();
    a[i].id = i;
  }
  m = rd();
  for (int i = 1; i <= m; i++) {
    b[i].s = rd(), b[i].t = rd(), b[i].k = rd();
    b[i].id = i;
  }
  std::sort(a + 1, a + n + 1);
  std::sort(b + 1, b + m + 1);
  int now = 1;
  for (int i = 1; i <= m; i++) {
    while (b[i].t >= a[now].t && now <= n)
      s.insert(std::make_pair((a[now].s), (now))), now++;
    while (b[i].k--) {
      std::set<std::pair<int, int> >::iterator it =
          s.upper_bound(std::make_pair((b[i].s), (0)));
      if (it == s.end()) break;
      ans[a[(*it).second].id] = b[i].id;
      s.erase(it);
    }
  }
  for (int i = 1; i <= n; i++)
    if (!ans[i]) return puts("NO") % 1;
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i ^ n ? ' ' : '\n');
  return 0;
}

#include <bits/stdc++.h>
char buf[100033];
int n, m;
int cnt[33];
struct node {
  int v, p;
  inline bool operator<(const node& T) const { return v > T.v; }
} e[33];
long long ans;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", buf);
  for (int i = (0), __ = (n); i < __; ++i) ++cnt[buf[i] - 'A'];
  for (int i = (0), __ = (26); i < __; ++i) {
    e[i].v = cnt[i];
    e[i].p = i;
  }
  std::sort(e, e + 26);
  for (int i = (0), __ = (26); i < __; ++i) {
    if (e[i].v > m) {
      ans += ((long long)m * m);
      break;
    } else {
      m -= e[i].v;
      ans += ((long long)e[i].v * e[i].v);
    }
  }
  printf("%d\n", ans);
  return 0;
}

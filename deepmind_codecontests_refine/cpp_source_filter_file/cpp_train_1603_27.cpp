#include <bits/stdc++.h>
const int maxn = 2e6 + 1;
template <class T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s & 15);
    s = getchar();
  }
  x *= f;
}
int n, m, to[maxn], cho[maxn], pos, l[maxn], r[maxn], ans, cov[maxn];
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(l[i]);
    read(r[i]);
    r[i] = (l[i] + r[i] - 1);
    if (r[to[l[i]]] < r[i]) to[l[i]] = i;
    cov[l[i]]++;
    cov[r[i] + 1]--;
  }
  for (int i = 1; i <= n; i++)
    if (r[to[i]] < r[to[i - 1]]) to[i] = to[i - 1];
  pos = 1;
  while (pos <= n) {
    while (r[to[pos]] < pos && pos <= n) pos++;
    if (pos > n) break;
    cho[to[pos]] = 1;
    pos = (r[to[pos]]) + 1;
    ans++;
  }
  printf("%d\n", m - ans);
  for (int i = 1; i <= m; i++)
    if (!cho[i]) printf("%d ", i);
}

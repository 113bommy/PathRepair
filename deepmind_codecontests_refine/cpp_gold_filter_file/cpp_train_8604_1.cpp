#include <bits/stdc++.h>
using namespace std;
set<int> s[400000];
int bl[400000], S[400000], sz, n, m;
void dfs(int x, int y) {
  bl[x] = y;
  ++sz;
  for (int z : s[x])
    if (z != 1 && !bl[z]) dfs(z, y);
}
void dft(int x) {
  S[x] = sz;
  for (int y : s[x])
    if (y != 1 && !S[y]) dft(y);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    s[x].insert(y);
    s[y].insert(x);
  }
  if (s[1].count(n)) return printf("1\n1 %d\n", n), 0;
  for (int x : s[1])
    if (s[x].count(n)) return printf("2\n1 %d %d\n", x, n), 0;
  for (int x : s[1])
    for (int y : s[x])
      if (s[y].count(n)) return printf("3\n1 %d %d %d\n", x, y, n), 0;
  for (int x : s[1])
    for (int y : s[x])
      if (y != 1 && !s[1].count(y))
        return printf("4\n1 %d %d 1 %d\n", x, y, n), 0;
  if (!s[1].size()) return puts("-1"), 0;
  for (int x : s[1])
    if (!bl[x]) {
      sz = 0;
      dfs(x, x);
      dft(x);
    }
  int mn = n + 10, mid = 0;
  for (int x : s[1])
    if (S[x] != s[x].size()) {
      if (s[x].size() < mn) {
        mn = s[x].size();
        mid = x;
      }
    }
  if (mid) {
    puts("5");
    for (int y : s[mid])
      if (y != 1)
        for (int z : s[y])
          if (z != 1 && z != mid && !s[mid].count(z))
            return printf("1 %d %d %d %d %d\n", mid, y, z, mid, n), 0;
  }
  puts("-1");
  return 0;
}

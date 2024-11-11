#include <bits/stdc++.h>
using namespace std;
int n, m, q, a[200000];
set<int> b[200000];
map<int, int> v[200000];
int find(int x) {
  if (a[x] == x) return x;
  a[x] = find(a[x]);
  return a[x];
}
void merge(int x, int y) {
  if (x == y) return;
  if (x == 0 || y == 0) return;
  if (b[x].size() > b[y].size()) swap(x, y);
  for (int i : b[x]) b[x].insert(i);
  a[x] = y;
}
void add(int x, int y, int z) {
  int xx = find(x), yy = find(y);
  b[xx].insert(y);
  b[yy].insert(x);
  merge(find(x), find(v[y][z]));
  merge(find(y), find(v[x][z]));
  v[x][z] = y;
  v[y][z] = x;
}
int check(int x, int y) {
  if (find(x) == find(y)) return 1;
  return b[a[x]].count(y);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &q, &q);
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
  }
  for (int i = 1; i <= q; i++) {
    int x, y, z;
    char ch = ' ';
    while (ch != '+' && ch != '?') scanf("%c", &ch);
    if (ch == '+') {
      scanf("%d%d%d", &x, &y, &z);
      add(x, y, z);
    } else {
      scanf("%d%d", &x, &y);
      if (check(x, y))
        puts("Yes");
      else
        puts("No");
    }
  }
}

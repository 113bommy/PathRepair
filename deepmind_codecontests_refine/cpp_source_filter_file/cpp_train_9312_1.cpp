#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
map<int, int> M;
int fa[110000], a, b, n, p[110000];
int get(int x) {
  if (fa[x] == x) return x;
  return fa[x] = get(fa[x]);
}
void Union(int x, int y) {
  fa[get(x)] = get(y);
  if (get(n + 1) == get(n + 2)) {
    puts("NO");
    exit(0);
  }
}
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]), M[p[i]] = i, fa[i] = i;
  fa[n + 1] = n + 1;
  fa[n + 2] = n + 2;
  for (int i = 1; i <= n; ++i) {
    int x = M[a - p[i]], y = M[b - p[i]];
    if (!x && !y) return puts("NO"), 0;
    if (!x)
      Union(i, n + 2), Union(y, n + 2);
    else if (!y)
      Union(i, n + 1), Union(x, n + 1);
    else
      Union(i, x), Union(i, y);
  }
  for (int i = 1; i <= n; ++i)
    if (get(i) != get(n + 1) && get(i) != get(n + 2)) Union(i, n + 1);
  puts("YES");
  for (int i = 1; i <= n; ++i)
    if (get(i) == n + 1)
      printf("0 ");
    else
      printf("1 ");
}

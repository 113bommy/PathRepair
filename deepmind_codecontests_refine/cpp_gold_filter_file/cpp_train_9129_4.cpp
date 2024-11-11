#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 35;
int n, m, a[N], x, y, id[M][2], ans;
long long c[M][2], t[N];
set<int> st[M];
int getint() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  int x = ch - 48;
  while (isdigit(ch = getchar())) x = x * 10 + ch - 48;
  return x;
}
void ins(int x, int y) {
  for (int i = x; i <= n; i += i & -i) t[i] += y;
}
long long query(int x) {
  long long rt = 0;
  for (int i = x; i; i -= i & -i) rt += t[i];
  return rt;
}
int get(int x) {
  int rt = 0;
  while (x) ++rt, x >>= 1;
  return rt;
}
void build(int x) {
  set<int>::iterator p = st[x].begin();
  id[x][0] = id[x][1] = c[x][0] = c[x][1] = 0;
  for (int tp = 0; tp < 2 && p != st[x].end(); ++tp, ++p)
    id[x][tp] = *p, c[x][tp] = query(*p - 1);
}
int main() {
  n = getint(), m = getint();
  for (int i = 1; i <= n; ++i) a[i] = t[i] = getint();
  for (int i = 1; i <= n; ++i)
    if (i + (i & -i) <= n) t[i + (i & -i)] += t[i];
  for (int i = 1; i <= n; ++i) st[get(a[i])].insert(i);
  for (int i = 0; i <= 30; ++i) build(i);
  while (m--) {
    x = getint(), y = getint();
    ins(x, y - a[x]);
    int p1 = get(a[x]), p2 = get(y);
    st[p1].erase(x), st[p2].insert(x);
    build(p1), build(p2);
    for (int i = 0; i <= 30; ++i)
      if (i != p1 && i != p2)
        for (int j = 0; j <= 1; ++j)
          if (id[i][j] > x) c[i][j] += y - a[x];
    a[x] = y, ans = -1;
    for (int i = 0; i <= 30; ++i) {
      for (int j = 0; j <= 1; ++j)
        if (id[i][j] && a[id[i][j]] == c[i][j]) {
          ans = id[i][j];
          break;
        }
      if (ans != -1) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}

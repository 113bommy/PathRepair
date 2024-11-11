#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
pair<int, int> a[maxn], ans[maxn];
int s[maxn], t[maxn], n, m, k, l;
bool v[maxn];
void init() {
  scanf("%d%d", &n, &m);
  s[1] = 1;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &t[i]);
    for (int j = 0; j < t[i]; ++j) {
      int x;
      scanf("%d", &x);
      a[x] = make_pair(i, j);
      v[x] = 1;
    }
    s[i + 1] = s[i] + t[i];
  }
  for (k = n; v[k]; --k)
    ;
}
int pos(int i, int x, int y) {
  if (!v[i]) return 0;
  return s[x] + y;
}
void find(int x) {
  int y;
  for (y; y <= n && pos(y, a[y].first, a[y].second) != x; ++y)
    ;
  if (x == y || y == n + 1) return;
  if (!v[x]) {
    ans[l++] = make_pair(y, x);
    swap(a[x], a[y]);
    v[y] = 0;
    v[x] = 1;
    k = y;
  } else {
    ans[l++] = make_pair(x, k);
    swap(a[x], a[k]);
    ans[l++] = make_pair(y, x);
    swap(a[x], a[y]);
    v[y] = 0;
    v[k] = v[x] = 1;
    k = y;
  }
}
void work() {
  for (int i = 1; i <= n; ++i) find(i);
  printf("%d\n", l);
  for (int i = 0; i < l; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
  init();
  work();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline void rd(int &x) {
  static char c;
  x = 0;
  while (c = getchar(), c < 48)
    ;
  do x = (x << 3) + (x << 1) + (c ^ 48);
  while (c = getchar(), c > 47);
}
map<int, int> cnt;
char op[10];
double dfs(int p, int mx) {
  if (cnt[p] <= mx)
    return mx;
  else
    return 0.5 * dfs(p << 1, max(mx, cnt[p] - cnt[p << 1])) +
           0.5 * dfs(p << 1 | 1, max(mx, cnt[p] - cnt[p << 1 | 1]));
}
int main() {
  int n, q;
  rd(n);
  rd(q);
  for (int i = (1), _t = (q); i <= _t; ++i) {
    int x, v;
    scanf("%s", op);
    if (op[0] == 'a') {
      rd(x);
      rd(v);
      for (; x; x >>= 1) cnt[x] += v;
    } else
      printf("%.5lf\n", dfs(1, 0));
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int c1, c2, c3, c4;
int n, m;
int memocar[1000], memotroy[1000];
int car[1000], troy[1000];
int func_car(int id) {
  if (id == -1) return 0;
  if (memocar[id] != -1) return memocar[id];
  int ans = 1000000000;
  ans = min(ans, (c1 * car[id]) + func_car(id - 1));
  ans = min(ans, c2 + func_car(id - 1));
  return memocar[id] = ans;
}
int func_troy(int id) {
  if (id == -1) return 0;
  if (memotroy[id] != -1) return memotroy[id];
  int ans = 1000000000;
  ans = min(ans, c1 * troy[id] + func_troy(id - 1));
  ans = min(ans, c2 + func_troy(id - 1));
  return memotroy[id] = ans;
}
int main(void) {
  memset(memocar, -1, sizeof memocar);
  memset(memotroy, -1, sizeof memotroy);
  scanf("%d %d %d %d", &c1, &c2, &c3, &c4);
  scanf("%d %d", &n, &m);
  for (int i = (0), _b = ((n)-1); i <= _b; i++) scanf("%d", &car[i]);
  for (int j = (0), _b = ((m)-1); j <= _b; j++) scanf("%d", &troy[j]);
  printf("%d\n", min(c4, min(c3, func_car(n - 1)) + min(c3, func_troy(m - 1))));
  return 0;
}

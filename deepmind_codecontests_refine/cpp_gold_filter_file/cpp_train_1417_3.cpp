#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 20;
int path[10];
long long num, ans;
int a[N], b[N];
long long l, r;
int solve(long long x, int *p) {
  int cnt = 0;
  while (x) {
    p[++cnt] = x % 10;
    x /= 10;
  }
  return cnt;
}
bool check(int pos, bool lst, bool rst) {
  if (!pos) return 1;
  if (!lst && !rst) return 1;
  int ed1 = lst ? a[pos] : 0;
  int ed2 = rst ? b[pos] : 9;
  for (int i = ed1; i <= ed2; i++) {
    if (path[i]) {
      path[i]--;
      if (check(pos - 1, lst && i == ed1, rst && i == ed2)) {
        path[i]++;
        return 1;
      }
      path[i]++;
    }
  }
  return 0;
}
void dfs(int res, int w) {
  if (res == 9) {
    path[res] = w;
    if (check(num, 1, 1)) ans++;
    return;
  }
  for (int i = 0; i <= w; i++) {
    path[res] = i;
    dfs(res + 1, w - i);
  }
}
int main() {
  scanf("%lld%lld", &l, &r);
  num = solve(l, a);
  num = solve(r, b);
  dfs(0, num);
  printf("%lld\n", ans);
  return 0;
}

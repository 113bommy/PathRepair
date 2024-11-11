#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, ans;
int h[7];
int get(int x) {
  int res = !x;
  while (x) res++, x /= 7;
  return res;
}
int pw(int x, int k) { return !k ? 1 : pw(x, k - 1) * x; }
void dfs(int x, long long v = 0) {
  if (!x) {
    int A = v / pw(7, b);
    int B = v % pw(7, b);
    ans += A < n and B < m;
    return;
  }
  for (int i = 0; i < 7; i++) {
    if (!h[i]) {
      h[i] = 1;
      dfs(x - 1, v * 7 + i);
      h[i] = 0;
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  a = get(n - 1);
  b = get(m - 1);
  dfs(a + b);
  printf("%d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int oo = ~0u >> 1;
int n, m, a, ans;
int b[100015], p[100015];
bool check(int x) {
  int sum = 0;
  ans = 0;
  for (int i = 0; i < x; i++) {
    sum += max(p[x - i - 1] - b[i], 0), ans += p[x - i - 1];
    if (sum > a) break;
  }
  if (sum <= a) return true;
  return false;
}
int main() {
  scanf("%d %d %d", &n, &m, &a);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < m; i++) scanf("%d", &p[i]);
  sort(b, b + n, greater<int>());
  sort(p, p + m);
  int l = 0, r = n, res = 0, anser = 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) {
      res = mid, anser = ans;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  printf("%d %d\n", res, max(anser - a, 0));
  return 0;
}

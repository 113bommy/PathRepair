#include <bits/stdc++.h>
using namespace std;
int n, m, ans[5010];
inline void write() {
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
inline bool check(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  m = (1 + n) * n / 2;
  for (int i = 1; i <= n; i++) ans[i] = 1;
  if (check(m)) return write(), 0;
  if ((m & 1) && !check(m - 2)) ans[3] = 3, m -= 3;
  for (int i = 2; i <= n; i++)
    if (check(i) && check(m - i)) {
      ans[i] = 2;
      break;
    }
  return write(), 0;
}

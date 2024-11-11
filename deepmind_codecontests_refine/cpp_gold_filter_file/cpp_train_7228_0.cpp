#include <bits/stdc++.h>
using namespace std;
const int N = 33;
int a[N], b[N], c[N], n;
bool dfs(int k) {
  if (!k) {
    for (int i = 1; i <= n; ++i)
      if (b[i] != a[i] - 1) return 0;
    return 1;
  }
  for (int i = n; i > k; --i)
    if (a[i] - a[k] > 1 && a[k] + b[i] < a[i]) {
      b[i] += a[k];
      if (dfs(k - 1)) return 1;
      b[i] -= a[k];
    }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  if (n == 1) {
    if (a[1] == 1)
      puts("YES");
    else
      puts("NO");
  } else {
    for (int i = 1; i <= n; ++i)
      if (a[i] == 2) {
        puts("NO");
        return 0;
      }
    if (a[n] == n && dfs(n - 1))
      puts("YES");
    else
      puts("NO");
  }
}

#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
vector<int> e;
int a[100010];
int main() {
  int n, m, k, x;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &x);
    a[x] = 1;
    e.push_back(x);
  }
  if (k == n || m == n * (n - 1) / 2) {
    printf("-1\n");
    return 0;
  }
  if (m + k - 1 > n * (n - 1) / 2) {
    printf("-1\n");
    return 0;
  }
  int p;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) p = i;
  }
  for (int i = 1; i <= n; i++) {
    if (i != p) printf("%d %d\n", p, i);
  }
  m -= n - 1;
  if (m == 0) return 0;
  for (int i = 1; i <= n; i++) {
    if (e[0] == i || i == e[1] || i == p) continue;
    for (int j = i + 1; j <= n; j++) {
      if (e[0] == j || j == e[1] || i == p) continue;
      printf("%d %d\n", i, j);
      m--;
      if (m == 0) return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (e[0] == i || i == e[1] || i == p) continue;
    printf("%d %d\n", i, e[0]);
    m--;
    if (m == 0) return 0;
    if (a[i] == 0) {
      printf("%d %d\n", i, e[1]);
      m--;
      if (m == 0) return 0;
    }
  }
}

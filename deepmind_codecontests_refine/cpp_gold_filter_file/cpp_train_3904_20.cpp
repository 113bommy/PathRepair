#include <bits/stdc++.h>
using namespace std;
int n, m, k;
inline bool work() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x <= 5 || y <= 5 || x >= n - 4 || y >= m - 4) return 1;
  }
  return 0;
}
int main() {
  if (work())
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int r, c;
    scanf("%d%d", &r, &c);
    if (r <= 3 || r >= n - 2 || c <= 3 || c >= m - 2) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}

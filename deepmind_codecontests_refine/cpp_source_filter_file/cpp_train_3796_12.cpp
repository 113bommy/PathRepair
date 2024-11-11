#include <bits/stdc++.h>
using namespace std;
int n, k, Ord[100000 + 5];
long long ans, Set[100000 + 5][5];
inline int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
int main() {
  scanf("%d%d", &n, &k);
  printf("%d\n", (n * 6 - 1) * k);
  for (int i = 0; i < n; i++)
    printf("%d %d %d %d\n", (1 + i * n) * k, (2 + i * n) * k, (3 + i * n) * k,
           (5 + i * n) * k);
  return 0;
}

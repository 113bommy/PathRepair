#include <bits/stdc++.h>
std::vector<long long int> v1[5002];
std::vector<long long int> v2[5002];
long long int max(long long int x, long long int y) {
  if (x > y) return x;
  return y;
}
int main() {
  long long int n, i, j, b;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &b);
    v1[i].push_back(b);
    v2[i].push_back(b);
  }
  for (i = 2; i <= n; i++) {
    for (j = 1; j < i; j++) {
      v1[i].push_back(v1[i][j - 1] ^ v1[i - 1][j - 1]);
      v2[i].push_back(max(v1[i][j], max(v2[i][j - 1], v2[i - 1][j - 1])));
    }
  }
  long long int q, x, y;
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld%lld", &x, &y);
    printf("%lld\n", v2[y - x][y]);
  }
  return 0;
}

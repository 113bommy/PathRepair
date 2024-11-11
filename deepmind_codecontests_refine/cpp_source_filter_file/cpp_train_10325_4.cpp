#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j;
  long long a, sum = 0, M;
  scanf("%d", &n);
  for (j = 0; j < n; j++) {
    scanf("%lld", &a);
    sum += a;
    M = max(M, a);
  }
  printf(((sum & 1) || (2 * M > sum)) ? "NO" : "YES");
  return 0;
}

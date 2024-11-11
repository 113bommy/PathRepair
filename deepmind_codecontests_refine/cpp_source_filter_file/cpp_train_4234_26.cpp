#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long X[15][15][15][15], A[15][2], B[15][2];
long long cross(long long a[2], long long b[2], long long c[2]) {
  return a[0] - b[0] * (c[1] - b[1]) - (a[1] - b[1]) * (c[0] - b[0]);
}
long long calc(long long a[2], long long b[2], long long c[2], long long d[2]) {
  return cross(a, b, c) * cross(a, b, d) > 0 &&
         cross(c, d, a) * cross(c, d, b) > 0;
}
long long O[11];
int main() {
  scanf("%lld%lld", &n, &m);
  if (n != m) {
    puts("No");
    return 0;
  }
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &A[i][0], &A[i][1]);
  for (long long i = 1; i <= m; i++) scanf("%lld%lld", &B[i][0], &B[i][1]);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++)
      for (long long k = 1; k <= n; k++)
        for (long long l = 1; l <= m; l++)
          X[i][j][k][l] = calc(A[i], B[j], A[k], B[l]);
  for (long long i = 1; i <= n; i++) O[i] = i;
  do {
    long long flag = 0;
    for (long long i = 1; i <= n; i++)
      for (long long j = i + 1; j <= n; j++)
        if (X[i][O[i]][j][O[j]]) {
          flag = 1;
          break;
        }
    if (!flag) {
      puts("Yes");
      return 0;
    }
  } while (next_permutation(O + 1, O + n + 1));
  puts("No");
  return 0;
}

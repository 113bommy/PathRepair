#include <bits/stdc++.h>
using namespace std;
long long combinatorial(long long x1, long long x2) {
  long long sum = 1, sum2 = 1;
  long long i;
  for (i = x1; i > x1 - x2; i--) sum *= i;
  for (i = 1; i <= x2; i++) sum2 *= i;
  return sum / sum2;
}
int main() {
  long long int i, n, v[100000], count, x[3];
  while (scanf("%lld", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%lld", &v[i]);
    sort(v, v + n);
    count = 0;
    if (v[0] == v[1] == v[2]) {
      for (i = 0; i < n; i++) {
        if (v[i] == v[0]) count++;
      }
      printf("%lld\n", combinatorial(count, 3));
      continue;
    } else if (v[0] == v[1]) {
      for (i = 0; i < n; i++) {
        if (v[i] == v[2]) count++;
      }
      printf("%lld\n", count);
      continue;
    } else if (v[1] == v[2]) {
      for (i = 0; i < n; i++) {
        if (v[i] == v[1]) count++;
      }
      printf("%lld\n", combinatorial(count, 2));
      continue;
    } else if (v[0] != v[1] && v[1] != v[2]) {
      for (i = 0; i < n; i++) {
        if (v[i] == v[2]) count++;
      }
      printf("%lld\n", count);
      continue;
    }
  }
  return 0;
}

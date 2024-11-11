#include <bits/stdc++.h>
using namespace std;
long long v[110], v1[20000010];
int main() {
  int n, l = 0;
  long long k, sol = 0;
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    k += v[i];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; 1LL * j * j <= v[i]; j++) {
      v1[++l] = j;
      v1[++l] = (v[i] + j - 1) / j;
    }
  sort(v1 + 1, v1 + l + 1);
  v1[0] = -1;
  for (int i = 1; i <= l; i++)
    if (v1[i] != v1[i - 1]) {
      long long s = 0;
      for (int j = 1; j <= n; j++) s += (v[j] + v1[i] - 1) / v1[i];
      long long d = k / s;
      if (v1[i] <= d) sol = max(sol, d);
    }
  printf("%lld", sol);
  return 0;
}

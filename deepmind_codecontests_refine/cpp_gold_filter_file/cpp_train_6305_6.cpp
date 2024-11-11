#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, a[4], K;
long long an;
int main() {
  for (i = 1; i <= 3; i++) scanf("%d", &a[i]), a[i]--;
  scanf("%d", &K);
  sort(a + 1, a + 4);
  an = 1;
  int A = min(a[1], K / 3);
  K -= A;
  an *= A + 1;
  A = min(a[2], K / 2);
  K -= A;
  an *= A + 1;
  A = min(K, a[3]);
  an *= A + 1;
  printf("%I64d\n", an);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10, maxk = 1e6 + 10;
int n, k, A[maxn], cnt[maxk], sum[maxk];
int32_t main() {
  scanf("%d%d", &n, &k);
  for (int i = int(0); i < int(n); i++) {
    scanf("%d", A + i);
    cnt[A[i]]++;
  }
  sort(A, A + n);
  for (int i = int(1); i < int(maxk); i++) {
    sum[i] = sum[i - 1] + cnt[i - 1];
  }
  int g, c = n, ans = 0;
  for (g = 1; g < maxk; g++) {
    c = 0;
    for (int j = g; j < maxk; j += g) {
      c += sum[min(maxk - 1, j + min(k + 1, g))] - sum[j];
    }
    if (c >= n) ans = g;
  }
  printf("%d\n", ans);
  return 0;
}

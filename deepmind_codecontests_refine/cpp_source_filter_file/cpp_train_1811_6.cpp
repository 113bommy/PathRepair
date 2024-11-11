#include <bits/stdc++.h>
using namespace std;
int n, can, a[201000], val[201000], b[201000];
int diff[1000100];
int flag[1000100], kas;
int cal(int mod);
int main() {
  int i, j, k, l, test, t = 1;
  scanf("%d %d", &n, &can);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      k = a[j] - a[i];
      if (k < 0) k *= -1;
      diff[k]++;
    }
  }
  sort(a + 1, a + n + 1);
  if (n <= can + 1) {
    printf("%d\n", 1);
    return 0;
  }
  int c1 = 1;
  for (i = 1;; i++) {
    if (i == 1) continue;
    kas = i;
    if (cal(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}
int cal(int mod) {
  int i, j, k, l;
  int ans = 0, ret = 0;
  for (i = mod; i <= a[n]; i += mod) {
    ans += diff[i];
  }
  if (ans > ((can * (can + 1)) / 2)) return 0;
  for (i = 1; i <= n; i++) {
    if (flag[i % mod] == kas) ret++;
    flag[i % mod] = kas;
    if (ret > can) return 0;
  }
  return 1;
}

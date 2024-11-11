#include <bits/stdc++.h>
int n, a, cnt, arr[1000007], occ[1000007], prev[1000007];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a);
    if (arr[a] == -1) continue;
    cnt += !arr[a];
    if (occ[a] <= 1)
      arr[a] = i - prev[a];
    else if (arr[a] != i - prev[a])
      arr[a] = -1, --cnt;
    prev[a] = i, ++occ[a];
  }
  printf("%d\n", cnt);
  for (int i = 1; i < 1000007; ++i) {
    if (occ[i] && arr[i] > -1) printf("%d %d\n", i, occ[i] == 1 ? 0 : arr[i]);
  }
  return 0;
}

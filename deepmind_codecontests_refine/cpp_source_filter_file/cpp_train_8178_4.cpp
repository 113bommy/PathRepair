#include <bits/stdc++.h>
using namespace std;
long long v[100001], best[100001], lg[100001];
int binarySearch(int ind, int range) {
  int step, ans = 0, r = v[ind] + 1 - range + 1;
  for (step = (1 << lg[ind]); step >= 1; step >>= 1)
    if (ans + step < ind && v[ans + step] < r) ans += step;
  return ans;
}
int main() {
  int n, i, pos1, pos2;
  long long sum;
  scanf("%d", &n);
  lg[2] = 1;
  for (i = 3; i <= n; ++i) lg[i] = lg[i / 2] + 1;
  for (i = 1; i <= n; ++i) scanf("%I64", &v[i]);
  best[1] = sum = 20;
  printf("20\n");
  for (i = 2; i <= n; ++i) {
    pos1 = binarySearch(i, 90);
    pos2 = binarySearch(i, 1440);
    best[i] = min(best[i - 1] + 20, best[pos1] + 50);
    best[i] = min(best[i], best[pos2] + 120);
    printf("%I64\n", best[i] - sum);
    sum += best[i] - sum;
  }
  return 0;
}

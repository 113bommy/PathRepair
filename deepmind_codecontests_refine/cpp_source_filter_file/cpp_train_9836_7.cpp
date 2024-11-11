#include <bits/stdc++.h>
using namespace std;
int w[200001], h[200001];
int main() {
  int n, sum = 0;
  int cnt = 0, ret = 0;
  scanf("%d", &n);
  int jl = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", w + i, h + i);
    if (h[i] > cnt) {
      ret = cnt;
      cnt = h[i];
    } else if (h[i] > ret)
      ret = h[i];
    sum += w[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (ret == h[i])
      printf("%d ", ret * (sum - w[i]));
    else
      printf("%d ", cnt * (sum - w[i]));
  }
  return 0;
}

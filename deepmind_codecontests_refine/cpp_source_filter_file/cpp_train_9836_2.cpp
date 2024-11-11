#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w[200020], h[200020];
  int totw = 0;
  int left[200020], right[200020];
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d %d\n", &w[i], &h[i]);
    totw += w[i];
    if (i > 0)
      left[i] = max(left[i - 1], h[i]);
    else
      left[i] = h[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1)
      right[i] = max(right[i], h[i]);
    else
      right[i] = h[i];
  }
  for (int i = 0; i < n; i++) {
    if (i == 0)
      printf("%d ", (totw - w[i]) * right[1]);
    else if (i < n - 1)
      printf("%d ", (totw - w[i]) * max(left[i - 1], right[i + 1]));
    else
      printf("%d ", (totw - w[i]) * left[i - 1]);
  }
  printf("\n");
  return 0;
}

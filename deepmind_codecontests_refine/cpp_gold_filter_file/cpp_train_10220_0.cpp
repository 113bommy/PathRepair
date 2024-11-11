#include <bits/stdc++.h>
int main() {
  int qs, length, k, mini, maxi, a;
  scanf("%d", &qs);
  while (qs--) {
    mini = INT_MAX;
    maxi = INT_MIN;
    scanf("%d %d", &length, &k);
    for (int i = 0; i < length; i++) {
      scanf("%d", &a);
      maxi = std::max(maxi, a);
      mini = std::min(mini, a);
    }
    if (maxi - mini > k * 2)
      printf("-1\n");
    else
      printf("%d\n", mini + k);
  }
}

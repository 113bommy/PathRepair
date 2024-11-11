#include <bits/stdc++.h>
using namespace std;
int main() {
  int nb, hno = -1e9, lpo = 1e9, sum = 0, curr;
  scanf("%d", &nb);
  for (int i = 0; i < nb; i++) {
    scanf("%d", &curr);
    if (curr > 0) {
      sum += curr;
      if (curr % 2 == 1) lpo = min(lpo, curr);
    } else if (curr < 0 && curr % 2 == -1)
      hno = max(hno, curr);
  }
  if (sum % 2 == 1)
    printf("%d\n", sum);
  else
    printf("%d\n", max(sum - abs(hno), sum - lpo));
  return 0;
}

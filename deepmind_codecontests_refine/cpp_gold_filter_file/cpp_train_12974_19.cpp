#include <bits/stdc++.h>
using namespace std;
int i, n, k, temp;
int main() {
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &temp);
    k -= (86400 - temp);
    if (k <= 0) {
      break;
    }
  }
  while (k > 0) {
    k -= 86400;
    i++;
  }
  printf("%d\n", i + 1);
}

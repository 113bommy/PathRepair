#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ctr = 0, pre = 0;
  while (n--) {
    int val = 0;
    scanf("%d", &val);
    if (val > 0 && k >= 0) {
      ctr++;
      pre = val;
    }
    if (k < 0 && val == pre && val > 0) ctr++;
    k--;
  }
  printf("%d\n", ctr);
  return 0;
}

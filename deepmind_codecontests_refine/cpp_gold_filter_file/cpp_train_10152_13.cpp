#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, m, n;
  long long int l, r;
  long long int k;
  scanf("%I64d%I64d%I64d", &l, &r, &k);
  bool first = true;
  long long int num = 1;
  for (i = 0; num <= 10e19; i++) {
    if (num <= r && num >= l) {
      if (first) {
        printf("%I64d", num);
        first = false;
      } else {
        printf(" %I64d", num);
      }
    }
    if (num > r / k) break;
    num = num * k;
  }
  if (first) {
    printf("-1");
  }
  printf("\n");
}

#include <bits/stdc++.h>
using namespace std;
const int loop[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
long long k, n;
int main() {
  scanf("%lld", &k);
  if (k > 36) {
    puts("-1");
    return 0;
  }
  if (k == 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < k / 2; ++i) {
    printf("8");
  }
  if (k % 2 == 1) printf("0");
  return 0;
}

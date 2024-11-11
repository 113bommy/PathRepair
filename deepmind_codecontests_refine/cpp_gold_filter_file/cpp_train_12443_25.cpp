#include <bits/stdc++.h>
using namespace std;
long long s, x, a;
long long otv, i;
int main() {
  scanf("%I64d %I64d", &s, &x);
  if ((s - x) & 1 == 1) {
    printf("0\n");
    return 0;
  }
  a = (s - x) >> 1;
  i = 0;
  while (true) {
    if ((x >> i) == 0) break;
    if ((x >> i) & 1 == 1 && (a >> i) & 1 == 1) {
      printf("0\n");
      return 0;
    }
    if ((x >> i) & 1 == 1) otv++;
    i++;
  }
  otv = 1ll << otv;
  if (a == 0) otv -= 2;
  otv = max(0ll, otv);
  printf("%I64d\n", otv);
  return 0;
}

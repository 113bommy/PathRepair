#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000");
using namespace std;
int main() {
  int n;
  long long L, R;
  scanf("%d", &n);
  long long ans = 0;
  while (n--) {
    scanf("%I64d %I64d", &L, &R);
    R = L + R - 1;
    if (L & 1) ans ^= L, L++;
    if (R - L + 1 >= 1) {
      long long sum = R - L + 1;
      if (sum % 4 == 1)
        ans ^= R;
      else if (sum % 4 == 2)
        ans ^= 1;
      else if (sum % 4 == 3)
        ans = ans ^ 1 ^ R;
    }
  }
  if (ans)
    printf("tolik\n");
  else
    printf("bolik\n");
  return 0;
}

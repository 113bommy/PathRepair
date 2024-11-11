#include <bits/stdc++.h>
using namespace std;
int sg(long long x) {
  if (x < 4)
    return 0;
  else if (x < 16)
    return 1;
  else if (x < 82)
    return 2;
  else if (x < 6724)
    return 0;
  else if (x < 50626)
    return 2;
  else if (x < 2562991876LL)
    return 1;
  else
    return 2;
}
int main() {
  int n;
  long long a, ret;
  while (~scanf("%d", &n)) {
    ret = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%I64d", &a);
      ret ^= sg(a);
    }
    if (ret == 0)
      puts("Rublo");
    else
      puts("Furlo");
  }
  return 0;
}

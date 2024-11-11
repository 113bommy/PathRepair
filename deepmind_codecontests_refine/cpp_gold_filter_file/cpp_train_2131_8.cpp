#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int lou, i;
  long long int ans = 0;
  scanf("%I64d", &lou);
  for (i = lou + 1; i <= 8888888888; i++) {
    long long int ii;
    if (i < 0) {
      ii = -i;
    } else {
      ii = i;
    }
    int flag = 0;
    while (ii) {
      if (ii % 10 == 8) {
        flag = 1;
        break;
      }
      ii /= 10;
    }
    ans++;
    if (flag == 1) break;
  }
  printf("%I64d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[10];
  scanf("%s", str);
  long long int ans1, ans2, i, j;
  int len = strlen(str);
  ans1 = pow(2, len) - 2;
  j = 0;
  for (i = len - 1; i >= 0; i--) {
    if (str[i] == '7') ans2 = ans2 + pow(2, j);
    j++;
  }
  printf("%lld\n", ans1 + ans2 + 1);
  return 0;
}

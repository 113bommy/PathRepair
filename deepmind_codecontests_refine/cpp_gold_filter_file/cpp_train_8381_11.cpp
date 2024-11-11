#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[300007];
  scanf("%s", &s);
  long long a = 0, n, sz, tmp = 0;
  sz = strlen(s);
  for (int i = 0; i < sz; i++) {
    n = s[i] - 48;
    if (n % 4 == 0) a++;
    if (i) {
      tmp = tmp * 10 + n;
      if (tmp % 4 == 0) a += i;
    }
    tmp = s[i] - 48;
  }
  printf("%I64d", a);
  return 0;
}

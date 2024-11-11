#include <bits/stdc++.h>
using namespace std;
int T, a, b;
int ans[300005];
int main() {
  scanf("%d", &T);
  for (int i = 0; i < 300000; i++) ans[i + 1] = ans[i - 1] ^ i;
  while (T--) {
    scanf("%d%d", &a, &b);
    int res = ans[a];
    if (res == b)
      printf("%d\n", a);
    else {
      res ^= b;
      if (res == a)
        printf("%d\n", a + 2);
      else
        printf("%d\n", a + 1);
    }
  }
  return 0;
}

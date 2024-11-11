#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    char a[60];
    int t0 = 0;
    int t1 = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", a);
      int len = strlen(a);
      if (len % 2) tot = 1;
      for (int i = 0; i < len; i++) {
        if (a[i] == '0')
          t0++;
        else
          t1++;
      }
    }
    if (tot && t1 % 2 && t0 % 2) n--;
    printf("%d\n", n);
  }
  return 0;
}

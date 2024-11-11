#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int main() {
  scanf("%s", a);
  int len = strlen(a) - 4;
  long int ans = 0, h = 0, i, j, k;
  for (i = 0; i < len; i++) {
    if (a[i] == 'h' && a[i + 1] == 'e' && a[i + 2] == 'a' && a[i + 3] == 'v' &&
        a[i + 4] == 'y') {
      i += 4;
      h++;
    } else if (a[i] == 'm' && a[i + 1] == 'e' && a[i + 2] == 't' &&
               a[i + 3] == 'a' && a[i + 4] == 'l') {
      i += 4;
      ans += h;
    }
  }
  printf("%ld\n", ans);
  return 0;
}

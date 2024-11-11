#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 100;
int main() {
  int n;
  char a[5], b[5];
  scanf("%s", a);
  scanf("%d", &n);
  int flag1 = 0, flag2 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", b);
    if (a[1] == b[1] && a[0] == b[0]) {
      flag1 = 1;
      flag2 = 1;
    } else {
      if (a[0] == b[1]) flag1 = 1;
      if (a[1] == b[0]) flag2 = 1;
    }
  }
  if (flag1 && flag2)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 10;
int B, u, l, b, a, s, r;
char str[MX];
int main() {
  while (~scanf("%s", str)) {
    int len = strlen(str);
    B = u = l = b = a = s = r = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] == 'B')
        B++;
      else if (str[i] == 'u')
        u++;
      else if (str[i] == 'l')
        l++;
      else if (str[i] == 'b')
        b++;
      else if (str[i] == 'a')
        a++;
      else if (str[i] == 's')
        s++;
      else if (str[i] == 'r')
        r++;
    }
    int ans = min(B, min(u / 2, min(l, min(b / 2, min(a / 2, min(s, r))))));
    printf("%d\n", ans);
  }
  return 0;
}

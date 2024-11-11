#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int inf = 0x3f3f3f3f;
char s[maxn];
int main() {
  scanf("%s", s);
  int len = strlen(s), k1 = 0, k2 = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == '1') {
      if (k1 >= k2)
        s[i] = '0', k2++;
      else
        k1++;
    } else
      k2++;
  }
  printf("%s\n", s);
}

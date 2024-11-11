#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
char s[N], p[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s, p);
    int slen = strlen(s), plen = strlen(p), n = 0, m = 0;
    for (int i = plen - 1; i >= 0; --i) {
      if (p[i] != '1')
        ++n;
      else
        break;
    }
    if (s[slen - n - 1] == '1') {
      puts("0");
      continue;
    }
    for (int i = slen - n - 1; i >= 0; --i) {
      if (s[i] != '1')
        ++m;
      else
        break;
    }
    printf("%d\n", m);
  }
}

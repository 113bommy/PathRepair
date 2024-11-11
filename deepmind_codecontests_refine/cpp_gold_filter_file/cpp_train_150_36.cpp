#include <bits/stdc++.h>
using namespace std;
int n, a, d, i;
char s[105];
int main() {
  scanf("%d%s", &n, s + 1);
  for (a = 1; a < 100; a++) {
    if (s[a] == '.') continue;
    for (d = 1; d < 100; d++) {
      if (a + 4 * d > n) continue;
      for (i = 1; i < 5; i++) {
        if (a + i * d > n || s[a + i * d] == '.') break;
      }
      if (i == 5) {
        puts("yes");
        return 0;
      }
    }
  }
  puts("no");
  return 0;
}

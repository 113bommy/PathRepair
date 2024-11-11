#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100010];
int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);
  if (n == 1 || m == 0) {
    printf("%s\n", s + 1);
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '4' && s[i + 1] == '7') {
      if (i % 2 == 1) {
        s[i + 1] = '4';
        m--;
      } else {
        if (s[i - 1] != '4') {
          s[i] = '7';
          m--;
        } else {
          if (m % 2 == 1)
            s[i] = '7';
          else
            s[i] = '4';
          break;
        }
      }
    }
    if (m == 0) break;
  }
  printf("%s\n", s + 1);
  return 0;
}

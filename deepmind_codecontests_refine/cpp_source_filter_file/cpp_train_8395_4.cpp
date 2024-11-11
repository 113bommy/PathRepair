#include <bits/stdc++.h>
using namespace std;
char s[64][64];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int f = 0, g = 0;
      for (int k = 0; k < m; k++) {
        if (s[i][k] == '#' || s[j][k] == '#') {
          if (s[i] == s[j])
            f = 1;
          else
            g = 1;
        }
      }
      if (f == 1 && g == 1) {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");
  return 0;
}

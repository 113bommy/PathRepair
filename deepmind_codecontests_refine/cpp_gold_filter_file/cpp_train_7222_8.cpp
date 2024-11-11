#include <bits/stdc++.h>
using namespace std;
char a[4][4];
int main() {
  for (int i = 0; i < 4; i++) scanf("%s", &a[i]);
  int b, n;
  bool puede = false;
  for (int i = 0; i < 3 && !puede; i++) {
    for (int j = 0; j < 3 && !puede; j++) {
      n = 0;
      b = 0;
      for (int k = i; k < i + 2; k++) {
        for (int u = j; u < j + 2; u++) {
          if (a[k][u] == '#')
            n++;
          else
            b++;
        }
      }
      if (b > 2 || n > 2) puede = true;
    }
  }
  if (puede)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

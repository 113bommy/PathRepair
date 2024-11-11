#include <bits/stdc++.h>
int main() {
  char g[100];
  scanf("%s", g);
  for (int w = 0; g[w] != '\0'; w++) {
    if (g[w] >= 65 && g[w] <= 90) g[w] = g[w] + 32;
  }
  for (int w = 0; g[w] != '\0'; w++) {
    if (!(g[w] == 'a' || g[w] == 'e' || g[w] == 'i' || g[w] == 'o' ||
          g[w] == 'u' || g[w] == 'y'))
      printf("%c", g[w]);
  }
}

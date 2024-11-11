#include <bits/stdc++.h>
using namespace std;
int c[10], i, j, n, p1, p2, k, m;
char ch, c1, c2;
bool kr, kg;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%c", &ch);
  kr = kg = false;
  for (int i = 1; i <= n; i++) {
    p1 = p2 = 0;
    for (int j = 1; j <= m; j++) {
      scanf("%c", &ch);
      if ((ch == 'R') || (ch == 'G')) {
        if (p1 == 0)
          p1 = j, c1 = ch;
        else
          p2 = j, c2 = ch;
      }
    }
    scanf("%c", &ch);
    if (p1 != 0) {
      if (((p2 == 0) && (m > 1)) || ((p2 != 0) && (m > 2) && (c1 == c2))) {
        if (c1 == 'G')
          kg = true;
        else
          kr = true;
      } else {
        int x = p2 - p1 - 1;
        for (int h = 1; h <= 10; h++)
          c[h] = (c[h] + (x % 2)) % (k + 1), x = x / 2;
      }
    }
  }
  if (kg && kr)
    puts("Draw");
  else if (kg)
    puts("First");
  else if (kr)
    puts("Second");
  else {
    kg = false;
    for (int i = 1; i <= 10; i++)
      if (c[i]) kg = true;
    if (kg)
      puts("First");
    else
      puts("Second");
  }
}

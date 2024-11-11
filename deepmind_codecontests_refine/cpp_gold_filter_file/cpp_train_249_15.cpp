#include <bits/stdc++.h>
using namespace std;
int a, b, n, maxB[100010], a1;
bool spr[100010][50];
long long p(int a, int b) {
  long long res = 1;
  for (int i = 0; i < b; i++) {
    res *= a;
    if (res >= n) break;
  }
  return res;
}
void dfs(int x, int y) {
  if (x == a1) {
    spr[x - a][y] = 1;
    return;
  }
  if (y == maxB[x - a]) {
    spr[x - a][y] = 1;
    return;
  }
  dfs(x + 1, y);
  dfs(x, y + 1);
  if (!spr[x + 1 - a][y] || !spr[x - a][y + 1]) spr[x - a][y] = 1;
}
int main() {
  scanf("%d%d%d", &a, &b, &n);
  for (a1 = max(a, 2); true; a1++) {
    for (int i = max(b, 2); true; i++)
      if (p(a1, i) >= n) {
        maxB[a1 - a] = i;
        break;
      }
    if (maxB[a1 - a] == max(b, 2)) break;
  }
  a1 = min(a1, n);
  for (int i = max(a, 2); i <= a1; i++) spr[i - a][maxB[i - a]] = 1;
  for (int i = a1; i >= max(a, 2); i--)
    for (int j = maxB[i - a] - 1; j >= max(b, 2); j--)
      if ((p(i, j + 1) < n && !spr[i - a][j + 1]) ||
          (p(i + 1, j) < n && !spr[i - a + 1][j]))
        spr[i - a][j] = 1;
  if (!spr[0][b]) {
    if ((p(a, b + 1) < n && !spr[0][b + 1] && a != 1) ||
        (p(a + 1, b) < n && !spr[1][b] && b != 1)) {
      printf("Masha\n");
      return 0;
    }
    if (b == 1) {
      bool ok = 1;
      int pom = a + 1;
      while (ok) {
        if (pom >= n) {
          ok = 0;
          break;
        }
        if (pom >= a1) break;
        if (p(pom, 2) < n && !spr[pom - a][2]) {
          ok = 0;
          break;
        }
        if (pom + 1 >= n) {
          printf("Masha\n");
          return 0;
        }
        pom++;
        if (p(pom, 2) < n && !spr[pom - a][2]) {
          printf("Masha\n");
          return 0;
        }
        pom++;
      }
      if (ok) {
        if (!((n - a) % 2)) {
          printf("Masha\n");
          return 0;
        }
      }
    }
    if (a == 1) {
      int pom = b + 1;
      while (true) {
        if (p(2, pom) >= n) break;
        if (p(2, pom) < n && !spr[1][pom]) {
          printf("Stas\n");
          return 0;
        }
        pom++;
        if (p(2, pom) < n && !spr[1][pom]) {
          printf("Masha\n");
          return 0;
        }
        pom++;
      }
      printf("Missing\n");
      return 0;
    }
    printf("Stas\n");
  } else
    printf("Masha\n");
  return 0;
}

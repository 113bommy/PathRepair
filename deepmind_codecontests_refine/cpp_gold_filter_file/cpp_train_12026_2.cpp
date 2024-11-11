#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, tl, tg;
int a[301][301], b[301][301];
int last[301], ans[301];
int gcd(int a, int b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  while (b != 0) {
    int c = a % b;
    a = b, b = c;
  }
  return a;
}
bool isok(int i, int j) {
  int temp = gcd(ans[i], ans[j]);
  if (temp != a[i][j]) return false;
  if (b[i][j] % ans[i] != 0) return false;
  if (b[i][j] / ans[i] * a[i][j] != ans[j]) return false;
  return true;
}
bool check(int t) {
  for (int i = 1; i <= n; i++)
    if (a[t][i] != 0) {
      if (ans[i] != 0)
        if (isok(i, t) == false) return false;
      if (ans[i] == 0) {
        if (b[i][t] % ans[t] != 0)
          return false;
        else {
          ans[i] = b[i][t] / ans[t] * a[i][t];
          bool pd = check(i);
          if (pd == false) {
            ans[i] = 0;
            return false;
          }
        }
      }
    }
  return true;
}
void clean(int t) {
  ans[t] = 0;
  for (int i = 1; i <= n; i++)
    if (a[t][i] && ans[i]) clean(i);
}
int main() {
  scanf("%d%d", &n, &m);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  while (m--) {
    scanf("%d%d%d%d", &x, &y, &tg, &tl);
    if (tl % tg != 0) {
      printf("NO\n");
      return 0;
    }
    a[x][y] = a[y][x] = tg;
    b[x][y] = b[y][x] = tl;
    last[x] = last[y] = tl;
  }
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= n; i++)
    if (ans[i] == 0) {
      while (ans[i] <= 1000000) {
        ans[i]++;
        if (last[i] % ans[i] == 0) {
          if (check(i)) break;
          int temp = ans[i];
          clean(i);
          ans[i] = temp;
        }
      }
      if (ans[i] > 1000000) {
        printf("NO\n");
        return 0;
      }
    }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    printf("%d", ans[i]);
    if (i != n)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}

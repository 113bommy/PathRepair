#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
char c[maxn], s[maxn];
int n, tot, mid;
bool flag;
int main() {
  scanf("%s", c);
  n = strlen(c);
  tot = 1;
  for (int i = 1; i <= n; i++)
    if (c[1] == c[i]) tot++;
  if (tot == n || (tot == n - 1 && n % 2)) {
    printf("Impossible\n");
    return 0;
  }
  if (n % 2) {
    printf("2\n");
    return 0;
  }
  mid = (n - 1) >> 1;
  for (int duan = 1; duan < n; duan++) {
    for (int i = 0; i < n - duan; i++) s[i] = c[i + duan];
    for (int i = 0; i < duan; i++) s[i + n - duan] = c[i];
    flag = true;
    for (int i = 0; i < n; i++)
      if (s[i] != c[i]) {
        flag = false;
        break;
      }
    if (flag) continue;
    flag = true;
    for (int i = 0; i <= mid; i++)
      if (s[i] != s[n - i - 1]) {
        flag = false;
        break;
      }
    if (flag) {
      printf("1\n");
      return 0;
    }
  }
  printf("2\n");
  return 0;
}

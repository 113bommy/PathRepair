#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
int i, j, k, n, a, b, m, ans, num, ch;
int s[N];
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &m);
  for (i = 1; i <= n; i++) {
    ch = getchar();
    while (ch != '0' && ch != '1') ch = getchar();
    s[i] = ch - '0';
  }
  for (i = 1; i <= n; i++)
    if (!s[i]) {
      j = i;
      while (j <= n && !s[j + 1]) j++;
      num += (j - i + 1) / b;
      i = j;
    }
  ans = num - a + 1;
  printf("%d\n", ans);
  j = 1;
  for (i = 1; i <= ans; i++) {
    num = 0;
    while (num < b) {
      while (s[j]) j++;
      num = 1;
      while (!s[j + 1]) {
        j++;
        num++;
        if (num == b) {
          s[j] = 1;
          printf("%d ", j);
          break;
        }
      }
    }
  }
  puts("");
}

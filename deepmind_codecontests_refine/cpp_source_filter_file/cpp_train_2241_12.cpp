#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int x[30];
char s[N][N];
int main() {
  int a, b, c, d, n;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  int cnt = 0, pos = 0, m = max(b, d);
  for (int i = 1; i <= a + c; i++) {
    if (i == a + 1) b = d;
    for (int j = 1; j <= m; j++) {
      int qwq = j;
      if (i % 2 == a % 2) qwq = b - j + 1;
      if (qwq <= 0) qwq += m;
      if (qwq > b) {
        s[qwq][i] = '.';
        continue;
      }
      if (cnt == x[pos]) {
        pos++;
        cnt = 0;
      }
      s[qwq][i] = 'a' + pos - 1;
      cnt++;
    }
  }
  printf("YES\n");
  for (int i = 1; i <= m; i++) printf("%s\n", s[i] + 1);
  return 0;
}

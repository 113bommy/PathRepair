#include <bits/stdc++.h>
using namespace std;
const int N = 150;
char s[N];
int main() {
  int n, m, r1 = 0, c1 = 0, r2, c2;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int j = 0; j < n; j++)
      if (s[j] == 'B') {
        if (r1 == 0) r1 = i;
        if (c1 == 0) c1 = j + 1;
        r2 = i, c2 = j + 1;
      }
  }
  printf("%d %d\n", (r1 + r2) / 2, (c1 + c2) / 2);
  return 0;
}

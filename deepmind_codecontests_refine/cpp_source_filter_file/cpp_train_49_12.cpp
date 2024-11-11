#include <bits/stdc++.h>
using namespace std;
int x[77], y[77], r[77];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", x + i, y + i, r + i);
  for (int i = 1; i < n; i++) printf("(");
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf("+");
    printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", x[i] / 2, i, i);
    if (i > 1) printf(")");
  }
  puts("");
  for (int i = 1; i < n; i++) printf("(");
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf("+");
    printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", x[i] / 2, i, i);
    if (i > 1) printf(")");
  }
  puts("");
  return 0;
}

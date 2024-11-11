#include <bits/stdc++.h>
using namespace std;
int x[100100], y[100100];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int r;
    scanf("%d%d%d", &x[i], &y[i], &r);
    x[i] /= 2;
    y[i] /= 2;
  }
  for (int i = 1; i < n; i++) printf("(");
  for (int i = 1; i <= n; i++) {
    printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", x[i], i, i);
    if (i > 1) printf(")");
    if (i < n) printf("+");
  }
  puts("");
  for (int i = 1; i < n; i++) printf("(");
  for (int i = 1; i <= n; i++) {
    printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", y[i], i, i);
    if (i > 1) printf(")");
    if (i < n) printf("+");
  }
  return 0;
}

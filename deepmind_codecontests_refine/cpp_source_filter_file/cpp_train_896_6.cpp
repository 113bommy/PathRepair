#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, nowmax;
  scanf("%d %d", &n, &m);
  nowmax = 0;
  int a, b;
  while (n--) {
    scanf("%d %d", &a, &b);
    if (nowmax < a)
      continue;
    else
      nowmax = max(nowmax, b);
  }
  if (nowmax >= b)
    printf("YES");
  else
    printf("NO");
}

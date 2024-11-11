#include <bits/stdc++.h>
using namespace std;
struct node {
  int x;
  bool first;
} a[100005];
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i <= 100004; i++) {
      a[i].x = 0;
      a[i].first = true;
    }
    int b, c;
    bool flag = true;
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &b, &c);
      if (!flag) continue;
      if (a[c].first && b != 0)
        flag = false;
      else if (a[c].first && b == 0)
        a[c].first = false;
      else if (a[c].x + 1 == b)
        a[c].x = b;
      else if (a[c].x >= b)
        continue;
      else
        flag = false;
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

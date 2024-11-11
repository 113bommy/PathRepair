#include <bits/stdc++.h>
using namespace std;
int d;
int cal(int x) { return x == d ? 1 : x + 1; }
int main() {
  int n, i, a, cur, ret = 0;
  scanf("%d %d", &d, &n);
  scanf("%d", &a);
  cur = cal(a);
  for (i = 1; i < n; i++) {
    scanf("%d", &a);
    if (cur > 1) {
      ret += d - cur + 1;
    }
    cur = cal(a);
  }
  printf("%d", ret);
  return 0;
}

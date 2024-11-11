#include <bits/stdc++.h>
using namespace std;
int p[3002][2];
int main() {
  int n, v, i, a, b, ret = 0;
  scanf("%d %d", &n, &v);
  while (n--) {
    scanf("%d %d", &a, &b);
    p[a][0] += b;
  }
  for (i = 1; i < 3002; i++) {
    if (p[i][0] + p[i][1] <= v)
      ret += p[i][0] + p[i][1];
    else {
      ret += v;
      if (p[i][1] > v)
        p[i + 1][1] += p[i][0];
      else
        p[i + 1][1] += p[i][0] + p[i][1] - v;
    }
  }
  printf("%d", ret);
  return 0;
}

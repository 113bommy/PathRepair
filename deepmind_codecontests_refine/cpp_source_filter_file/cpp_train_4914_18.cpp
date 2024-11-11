#include <bits/stdc++.h>
using namespace std;
long long a, an[1001][1001];
struct p {
  long long q, w;
} d[100001];
bool cmp(p qq, p ww) { return qq.q > ww.q; }
int main() {
  scanf("%lld", &a);
  for (int i = 1; i <= a; i++) {
    d[i].w = i;
    scanf("%lld", &d[i].q);
  }
  sort(d + 1, d + a + 1, cmp);
  for (int i = 1; i <= a; i++) {
    long long tt = d[i].w, gg = d[i].q;
    for (int j = tt; j <= min(a + 1, tt + gg - 1); j++) {
      an[j][tt] = 1;
      d[i].q--;
    }
    for (int j = 1; j <= d[i].q; j++) {
      an[j][tt] = 1;
    }
  }
  printf("%lld\n", a + 1);
  for (int i = 1; i <= a + 1; i++) {
    for (int j = 1; j <= a; j++) {
      printf("%lld", an[i][j]);
    }
    printf("\n");
  }
  return 0;
}

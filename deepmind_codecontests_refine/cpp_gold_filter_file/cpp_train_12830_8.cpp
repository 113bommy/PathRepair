#include <bits/stdc++.h>
using namespace std;
int f[200005], v[100005];
int main() {
  int t, i1, n, i, x;
  scanf("%d", &t);
  for (i1 = 1; i1 <= t; i1++) {
    scanf("%d", &n);
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);
    int rasp = 1, cur = 0;
    for (i = 1; i <= n; i++)
      if (v[i] <= rasp + cur)
        rasp = rasp + cur + 1, cur = 0;
      else
        cur++;
    printf("%d\n", rasp);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int _max = 1e5 + 10;
typedef int ints[_max];
int n, u, v;
ints deg, a;
int cnt;
int x, d, ok;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
  }
  for (int i = 1; i <= n; i++)
    if (deg[i] == 1)
      a[cnt++] = i;
    else if (deg[i] > 2)
      x = i, d = deg[i];
  if (d == 0)
    printf("Yes\n1\n%d %d", a[0], a[1]);
  else if (d == cnt) {
    printf("Yes\n%d\n", cnt);
    for (int i = 0; i < cnt; i++) printf("%d %d\n", x, a[i]);
  } else
    printf("No");
  return 0;
}

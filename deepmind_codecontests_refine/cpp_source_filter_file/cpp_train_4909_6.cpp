#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000000 + 5;
bitset<maxn> vis;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (b < 2)
    return puts("0");
  else {
    int ans = 0;
    if (a <= 2) ans = 1;
    int lim = sqrt(b);
    for (int i = 3; i <= lim; i += 2)
      if (!vis[i]) {
        for (int j = i * i; j <= b; j += 2 * i) vis[j] = 1;
      }
    while (a % 4 != 1) a++;
    for (int i = a; i <= b; i += 4) ans += !vis[i];
    printf("%d\n", ans);
  }
  return 0;
}

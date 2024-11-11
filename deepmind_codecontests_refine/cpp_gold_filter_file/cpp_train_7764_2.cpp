#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
char str[maxn];
int main(void) {
  long long n, q, u;
  cin >> n >> q;
  int depth = 0;
  while ((n + 1) != (1ll << depth)) depth++;
  for (int i = 0; i < q; i++) {
    scanf("%lld", &u);
    long long rt = (n + 1) / 2, nd = depth - 2;
    while (rt != u) {
      if (rt < u)
        rt += (1ll << nd);
      else
        rt -= (1ll << nd);
      nd--;
    }
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
      if (str[i] == 'U') {
        if (nd == depth - 2) continue;
        if (rt & (1ll << (2 + nd)))
          rt -= (1ll << (1 + nd));
        else
          rt += (1ll << (1 + nd));
        nd++;
      } else if (str[i] == 'L') {
        if (nd < 0) continue;
        rt -= (1ll << nd);
        nd--;
      } else if (str[i] == 'R') {
        if (nd < 0) continue;
        rt += (1ll << nd);
        nd--;
      }
    }
    printf("%lld\n", rt);
  }
}

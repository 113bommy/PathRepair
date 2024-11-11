#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 5;
const int inf = (int)1e9 + 9;
const double eps = 1e-8;
const double pi = 3.141592653589793238462643;
int n, ans = 0;
int main() {
  scanf("%d", &n);
  int st[(int)1e6 + 9], it = 0;
  for (int i = 0; i < n; ++i) {
    int q;
    scanf("%d", &q);
    while (it > 0) {
      if ((q ^ st[it]) > ans) ans = (q ^ st[it]);
      if (q > st[it])
        it--;
      else
        break;
    }
    st[++it] = q;
  }
  printf("%d\n", ans);
  return 0;
}

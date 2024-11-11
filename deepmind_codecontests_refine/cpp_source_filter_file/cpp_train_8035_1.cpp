#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
const int N = 3e5 + 5;
int q, n;
int tab[N], al[N], what[N], fir[N], last[N], best[N];
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tab[i]);
      al[i] = tab[i];
    }
    sort(al + 1, al + n + 1);
    int wks = 0;
    al[0] = -1;
    for (int i = 1; i <= n; i++)
      if (al[i] != al[i - 1]) {
        what[al[i]] = ++wks;
      }
    for (int i = 1; i <= n; i++) {
      tab[i] = what[tab[i]];
      last[tab[i]] = i;
    }
    for (int i = n; i > 0; i--) fir[tab[i]] = i;
    int ans = wks - 1;
    for (int i = n; i > 0; i--) {
      int t = tab[i];
      if (fir[t] != i) continue;
      int g = t + 1;
      if (g == wks + 1)
        best[i] = 1;
      else {
        if (fir[g] > last[t])
          best[i] = 1 + best[fir[g]];
        else
          best[i] = 0;
      }
      ans = min(ans, wks - best[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}

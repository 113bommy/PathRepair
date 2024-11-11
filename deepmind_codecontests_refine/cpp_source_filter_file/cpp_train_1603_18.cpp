#include <bits/stdc++.h>
using namespace std;
int n, m;
struct range {
  int a, l;
} rg[200020];
int farest[2000020], used[2000020], ans;
int main() {
  cin >> n >> m;
  ans = m;
  for (int i = 1; i <= m; ++i) {
    cin >> rg[i].a >> rg[i].l;
    farest[rg[i].a] = max(farest[rg[i].a], rg[i].a + rg[i].l - 1);
  }
  int i = 1;
  for (; !farest[i]; ++i)
    ;
  while (i <= n) {
    used[i] = 1;
    ans--;
    int maxr = farest[i];
    int best = maxr;
    for (int j = i + 1; j <= maxr; j++) {
      if (farest[j] > best) {
        i = j;
        best = farest[j];
      }
    }
    if (best == maxr) {
      for (i = maxr + 1; !farest[i] && i <= n; ++i)
        ;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= m; ++i) {
    if (!(used[rg[i].a] && farest[rg[i].a] == rg[i].a + rg[i].l - 1)) {
      cout << i << " ";
    } else {
      used[rg[i].a] = 0;
    }
  }
}

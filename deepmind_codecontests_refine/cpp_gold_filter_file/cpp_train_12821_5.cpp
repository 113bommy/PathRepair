#include <bits/stdc++.h>
using namespace std;
int n, r[1010], c[1010], rc[1010], rr[1010], tr[1010], tc[1010], rtc[1010],
    rtr[1010];
class portal {
 public:
  int ix, iy, ox, oy;
};
vector<portal> ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &r[i]);
    rr[r[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    rc[c[i]] = i;
  }
  for (int i = 1; i <= n; i++) tr[i] = tc[i] = rtr[i] = rtc[i] = i;
  for (int i = 1; i <= n; i++) {
    if (tc[i] == rc[i] && tr[i] == rr[i]) continue;
    ans.push_back((portal){i, rtc[rc[i]], rtr[rr[i]], i});
    int t1 = tc[i], t2 = tr[i];
    swap(tc[i], tc[rtc[rc[i]]]);
    swap(tr[i], tr[rtr[rr[i]]]);
    swap(rtc[rc[i]], rtc[t1]);
    swap(rtr[rr[i]], rtr[t2]);
  }
  printf("%d\n", ans.size());
  for (portal x : ans) printf("%d %d %d %d\n", x.ix, x.iy, x.ox, x.oy);
  return 0;
}

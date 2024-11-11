#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, pp = 317;
const int maxn = 1e6 + 10;
long long a[maxn], k[maxn], n, sum[pp], sk[maxn];
set<int> st;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) {
    if (i > 0) k[i] += k[i - 1];
    sum[i / pp] += a[i];
    st.insert(i);
  }
  st.insert(n);
  for (int i = 1; i < n; i++) sk[i] = sk[i - 1] + k[i];
  int q;
  scanf("%d", &q);
  while (q--) {
    char op[20];
    scanf("%s", op);
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    if (op[0] == 's') {
      x--;
      y--;
      long long ans = 0;
      auto it = --st.upper_bound(x);
      int pre = *it;
      int nxt = *(++it);
      for (int i = x; i < x / pp * pp + pp && i <= y; i++) {
        if (i == nxt) {
          pre = nxt;
          nxt = *(++it);
        }
        ans += a[pre] + k[i] - k[pre];
      }
      for (int i = x / pp + 1; i * pp + (pp - 1) < y; i++) {
        ans += sum[i];
      }
      it = --st.upper_bound(y / pp * pp);
      pre = *it;
      nxt = *(++it);
      if (x / pp < y / pp)
        for (int i = y / pp * pp; i <= y; i++) {
          if (i == nxt) {
            pre = nxt;
            nxt = *(++it);
          }
          ans += a[pre] + k[i] - k[pre];
        }
      printf("%I64d\n", ans);
    } else {
      x--;
      auto it = --st.upper_bound(x);
      int pre = *it;
      int nxt = *(++it);
      a[x] = a[pre] + k[x] - k[pre] + y;
      pre = x;
      while (1) {
        int l = pre / pp, r = (nxt - 1) / pp, pl = l * pp + pp - 1, pr = r * pp;
        sum[l] += y * 1LL * (pl - pre + 1);
        sum[r] += y * 1LL * (nxt - pr);
        for (int i = l + 1; i < r; i++) sum[i] += y * pp;
        if (l == r) sum[l] -= y * pp;
        y = (a[x] + k[nxt] - k[x]) - a[nxt];
        pre = nxt;
        auto pit = it++;
        if (it == st.end() || y < 0) break;
        nxt = *it;
        st.erase(pit);
      }
      st.insert(x);
    }
  }
  return 0;
}

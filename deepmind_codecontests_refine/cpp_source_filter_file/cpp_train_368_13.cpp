#include <bits/stdc++.h>
using namespace std;
set<int> st, st2;
int n, w, k, a[200010], t[200010], j, vis[20010], sz, b[20010];
long long tot, ans, s[200010];
int main() {
  scanf("%d%d%d", &n, &w, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
  j = 1;
  for (int i = 1; i <= n; i++) {
    for (; j <= n; j++) {
      int we = t[j];
      if (sz < w) {
        if (tot + (we + 1) / 2 > k) break;
        if (!vis[we]) st.insert(we);
        tot += (we + 1) / 2;
        vis[we]++;
        sz++;
      } else {
        int x = *st.begin();
        if (x > we) {
          if (tot + we > k) break;
          tot += we;
          if (!b[we]) st2.insert(we);
          b[we]--;
        } else {
          if (tot + (we + 1) / 2 + x - (x + 1) / 2 > k) break;
          if (!vis[we]) st.insert(we);
          vis[we]++;
          tot += (we + 1) / 2;
          tot -= (x + 1) / 2;
          tot += x;
          if (vis[x] == 1) st.erase(x);
          vis[x]--;
          if (!b[x]) st2.insert(x);
          b[x]++;
        }
      }
    }
    ans = max(ans, s[j - 1] - s[i - 1]);
    if (!vis[t[i]]) {
      tot -= t[i];
      if (b[t[i]] == 1) st2.erase(t[i]);
      b[t[i]]--;
    } else {
      if (vis[t[i]] == 1) st.erase(t[i]);
      tot -= (t[i] + 1) / 2;
      vis[t[i]]--;
      sz--;
      if (!st2.empty()) {
        int tmp = *(--st2.end());
        if (b[tmp] == 1) st2.erase(tmp);
        b[tmp]--;
        if (!vis[tmp]) st.insert(tmp);
        tot -= tmp;
        tot += (tmp + 1) / 2;
        vis[tmp]++;
        sz++;
      }
    }
  }
  printf("%I64d", ans);
  return 0;
}

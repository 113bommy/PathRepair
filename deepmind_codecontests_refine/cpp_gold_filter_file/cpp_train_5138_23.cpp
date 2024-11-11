#include <bits/stdc++.h>
using namespace std;
int n;
set<pair<int, int> > s;
int st[5005], k[5005], w[5005], data[25000005], cnt, ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a1, x, y, m, ts = 0;
    scanf("%d %d %d %d %d", &k[i], &a1, &x, &y, &m);
    for (int j = 1; j <= k[i]; j++) {
      data[++cnt] = a1;
      if (j == 1) st[i] = cnt;
      int b = (1ll * a1 * x + y) % m;
      if (j < k[i] && a1 > b) ts++;
      a1 = b;
    }
    ans = max(ans, ts);
    w[i] = 1;
    s.insert(make_pair(data[st[i]], i));
  }
  printf("%d\n", ans);
  if (cnt > 200000) return 0;
  int lst = 0x3f3f3f3f;
  for (int i = 1; i <= cnt; i++) {
    set<pair<int, int> >::iterator it =
        lower_bound(s.begin(), s.end(), make_pair(lst, 0));
    if (it == s.end()) it = s.begin();
    int val = (*it).first, a = (*it).second;
    printf("%d %d\n", val, a);
    s.erase(*it);
    w[a]++;
    if (w[a] <= k[a]) s.insert(make_pair(data[st[a] + w[a] - 1], a));
    lst = val;
  }
}

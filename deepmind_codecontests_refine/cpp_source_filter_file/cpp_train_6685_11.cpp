#include <bits/stdc++.h>
using namespace std;
int t, l[200005], r[200005], b[200005], n, m, a[200005], ans;
map<int, int> mp;
set<int> sets;
set<int>::iterator it;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    m = 0;
    mp.clear();
    sets.clear();
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
      b[++m] = l[i];
      b[++m] = r[i];
    }
    sort(b + 1, b + m + 1);
    m = unique(b + 1, b + m + 1) - b - 1;
    for (int i = 1; i <= m; i++) mp[b[i]] = i;
    for (int i = 1; i <= n; i++) {
      l[i] = mp[l[i]], r[i] = mp[r[i]];
      l[i] *= 2;
      l[i]--;
      r[i] *= 2;
      r[i]--;
      a[l[i]]++;
      a[r[i] + 1]--;
    }
    m *= 2;
    for (int i = 1; i <= m; i++) {
      a[i] = a[i - 1] + a[i];
      if (a[i] == 1) sets.insert(i);
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++)
      if (a[i] && a[i + 1] == 0) cnt++;
    ans = cnt;
    if (ans == n) ans--;
    if (!sets.empty())
      for (int i = 1; i <= n; i++) {
        int mx = 0;
        it = sets.upper_bound(r[i]);
        it--;
        if (*it >= l[i] && *it <= r[i]) {
          for (int j = l[i]; j <= r[i] - 1; j++)
            if (a[j] == 1 && a[j + 1] != 1) mx++;
          if (a[l[i]] == 1) mx--;
          ans = max(cnt + mx, ans);
        }
      }
    cout << ans << endl;
  }
}

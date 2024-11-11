#include <bits/stdc++.h>
using namespace std;
int long long t, n, i, l, r, m, k, cnt, ans, sum;
multiset<int long long> me, my[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t) {
    t--;
    cin >> n;
    for (i = 1; i <= n; i++) {
      int x, q;
      cin >> x >> q;
      my[x].insert(q);
    }
    cnt = my[0].size();
    sum = 0;
    my[0].clear();
    ans = 0;
    l = 0;
    while (l <= cnt) {
      cnt += my[l].size();
      my[l].clear();
      l++;
    }
    for (i = n; i >= l; i--) {
      int x = my[i].size();
      sum += x;
      while (!my[i].empty()) {
        me.insert(*my[i].begin());
        my[i].erase(my[i].begin());
      }
      while (i > n - sum) {
        if (me.empty()) {
          cout << -1;
          return 0;
        }
        ans += *me.begin();
        sum--;
        cnt++;
        me.erase(me.begin());
        while (l <= cnt) {
          cnt += my[l].size();
          my[l].clear();
          l++;
        }
      }
    }
    for (i = 0; i < n; i++) my[i].clear();
    cout << ans << endl;
    me.clear();
  }
}

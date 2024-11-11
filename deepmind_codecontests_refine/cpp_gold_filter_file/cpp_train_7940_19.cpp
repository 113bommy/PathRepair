#include <bits/stdc++.h>
using namespace std;
int qq, n, m, k, l, r;
string s, s1, s2, s3;
int INF = (int)1e9 + 7;
struct st {
  long long mi, ma, mir, mar, mir2, mar2;
};
vector<st> v;
multimap<int, st> ma;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ans = 0;
  int t, x = 1, y = n, k1 = 0, k2, k3, k4, x1, x2;
  k = 0;
  cin >> n >> k;
  vector<int> a, b(k), c, dp;
  for (int i = 0; i < n; i++) {
    cin >> m;
    m -= i;
    a.push_back(m);
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < k; i++)
    if (a[b[i] - 1] < a[b[i - 1] - 1]) {
      cout << -1;
      return 0;
    }
  k1 = 0;
  if (b.size() && b[0] == 1) {
    k3 = a[0];
    k1 = 0;
  } else {
    k1 = -1;
    k3 = -INF;
  }
  for (int j : b) {
    for (int i = k1 + 1; i < j; i++) {
      if (a[i] > a[j - 1] || a[i] < k3)
        ans++;
      else
        c.push_back(a[i]);
    }
    if (c.size()) {
      dp.clear();
      dp.push_back(c[0]);
      for (int i = 1; i < c.size(); i++) {
        k2 = upper_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
        if (k2 == dp.size())
          dp.push_back(c[i]);
        else
          dp[k2] = c[i];
      }
      ans += c.size() - dp.size();
    }
    k1 = j - 1;
    k3 = a[j - 1];
    c.clear();
  }
  k1 = -1;
  k3 = -INF;
  if (b.size()) {
    k1 = b[k - 1] - 1;
    k3 = a[b[k - 1] - 1];
  }
  for (int i = k1 + 1; i < n; i++) {
    if (a[i] < k3)
      ans++;
    else
      c.push_back(a[i]);
  }
  if (c.size()) {
    dp.clear();
    dp.push_back(c[0]);
    for (int i = 1; i < c.size(); i++) {
      k2 = upper_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
      if (k2 == dp.size())
        dp.push_back(c[i]);
      else
        dp[k2] = c[i];
    }
    ans += c.size() - dp.size();
  }
  cout << ans << endl;
  cin >> k;
  return 0;
}

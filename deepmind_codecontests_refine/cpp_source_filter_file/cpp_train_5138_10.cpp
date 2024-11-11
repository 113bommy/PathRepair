#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 10;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    st[2];
int a[maxn], cnt[maxn];
int x[maxn], y[maxn], m[maxn];
vector<pair<int, int> > ant;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p = 0;
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> cnt[i] >> a[i] >> x[i] >> y[i] >> m[i];
  for (int i = (0); i < (n); ++i) p += cnt[i];
  int ans = 0, q = 0;
  if (p <= 200000) {
    for (int i = (0); i < (n); ++i) {
      st[0].push(make_pair(a[i], i));
      cnt[i]--;
    }
    while (!st[1].empty() || !st[0].empty()) {
      if (st[q].empty()) {
        ++ans;
        q = !q;
      } else {
        pair<int, int> it = st[q].top();
        st[q].pop();
        ant.push_back(it);
        if (cnt[it.second]) {
          --cnt[it.second];
          long long gt =
              (1ll * it.first * x[it.second] + y[it.second]) % m[it.second];
          if (gt >= it.first) {
            st[q].push(make_pair(gt, it.second));
          } else {
            st[!q].push(make_pair(gt, it.second));
          }
        }
      }
    }
    cout << ans << '\n';
    for (pair<int, int> it : ant)
      cout << it.first << ' ' << it.second + 1 << '\n';
  } else {
    int ans = 1;
    for (int i = (0); i < (n); ++i) {
      int q = 1;
      for (int j = (0); j < (cnt[i] - 1); ++j) {
        long long gt = (a[i] * x[i] + y[i]) % m[i];
        q += gt < a[i];
        a[i] = gt;
      }
      ans = max(q, ans);
    }
    cout << ans;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 200010;
LL x[MAXN];
int p[MAXN];
vector<LL> y[MAXN];
LL ans[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  LL k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 1; i < n; ++i) {
    if (p[i - 1] > p[i] || p[i] <= i) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && p[j] == p[i]) ++j;
    for (int l = i; l < p[i] - 1; ++l) {
      ans[l] = x[l + 1] + k;
    }
    if (j == p[i]) {
      ans[p[i] - 1] = x[p[i] - 1] + k;
    } else {
      ans[p[i] - 1] = x[p[i]] + k;
    }
    i = p[i];
  }
  LL prev = -1;
  for (int i = 0; i < n; ++i) {
    if (ans[i] <= prev) {
      ans[i] = prev + 1;
    }
    prev = ans[i];
  }
  set<pair<LL, int>> s;
  for (int i = 0; i < n; ++i) s.insert({ans[i], i});
  for (int i = n - 1; i >= 0; --i) {
    if (s.rbegin()->second > p[i] - 1) {
      cout << "No\n";
      return 0;
    }
    auto iter = s.lower_bound({x[i] + k, -1});
    s.erase(iter);
  }
  cout << "Yes\n";
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}

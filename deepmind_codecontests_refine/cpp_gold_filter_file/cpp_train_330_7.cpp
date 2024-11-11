#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const double EPS = 1e-6;
const int MAX_N = 4e5 + 5;
int a[MAX_N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; ++tt) {
    int n;
    cin >> n;
    int cur = 0;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i] = x;
      if (i > 0 && a[i] < a[i - 1]) {
        v.push_back(make_pair(a[i - 1], cur));
        cur = 0;
      }
      ++cur;
    }
    v.push_back(make_pair(a[n - 1], cur));
    vector<pair<int, int> > use;
    int idx = 0;
    long long sum = 0;
    while (idx < int(v.size()) && sum + v[idx].second <= n / 2) {
      sum += v[idx].second;
      use.push_back(v[idx]);
      ++idx;
    }
    if (idx < 3) {
      cout << "0 0 0\n";
      continue;
    }
    long long pre[MAX_N]{};
    pre[0] = use[1].second;
    for (int i = 1; i < int(use.size()) - 1; ++i) {
      pre[i] = pre[i - 1] + use[i + 1].second;
    }
    bool works = false;
    long long ag = use[0].second, as = 0, ab = 0;
    for (int i = 0; i < int(use.size()); ++i) {
      if (ag < pre[i] && ag < sum - ag - pre[i]) {
        as = pre[i];
        ab = sum - ag - pre[i];
        works = true;
        break;
      }
    }
    if (works) {
      cout << ag << ' ' << as << ' ' << ab << '\n';
    } else {
      cout << "0 0 0\n";
    }
  }
  return 0;
}

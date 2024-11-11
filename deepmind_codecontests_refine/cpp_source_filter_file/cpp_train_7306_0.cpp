#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 10;
const int M = 1000 * 1000 * 1000 + 7;
const long long INFLL = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000;
const int SZ = 1e5 + 10;
int cnt[SZ];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  long long mt = 0;
  long long ones = 0;
  vector<int> a(n);
  for (int &t : a) {
    cin >> t;
    mt = max(mt, (long long)t);
    if (t == 1) ones++;
  }
  const int T = ceil(pow(mt * mt, 1.0 / k));
  vector<vector<pair<int, int> > > ds(n);
  vector<int> mc(n);
  long long ans = 0;
  for (int q = 0; q < n; ++q) {
    int t = a[q];
    int f = t;
    vector<int> divs;
    for (int i = 2; i <= f / i; ++i) {
      while (f % i == 0) {
        divs.push_back(i);
        f /= i;
      }
    }
    if (t == 1 || f > 1) divs.push_back(f);
    sort(divs.begin(), divs.end());
    int c = 1;
    for (int i = 1; i <= divs.size(); ++i) {
      if (i == divs.size() || divs[i] != divs[i - 1]) {
        int v = 1;
        for (int j = 0; j < c - c % k; ++j) v *= divs[i - 1];
        a[q] /= v;
        t /= v;
        if (c % k != 0) ds[q].emplace_back(divs[i - 1], c % k);
        c = 1;
        mc[q] = max(c, mc[q]);
      } else {
        c++;
      }
    }
    cnt[t]++;
  }
  for (int q = 0; q < n; ++q) {
    long long e = 1;
    for (int i = (mc[q] + k - 1) / k * k; i <= T; i += k) {
      bool superbreak = false;
      for (int j = 0; j < ds[q].size(); ++j) {
        for (int h = 0; h < i - ds[q][j].second; ++h) {
          e *= ds[q][j].first;
          if (e > mt) {
            superbreak = true;
            break;
          }
        }
        if (superbreak) break;
      }
      if (superbreak) break;
      ans += cnt[e] - (e == a[q]);
      if (a[q] == 1) break;
    }
  }
  cout << ans / 2;
}

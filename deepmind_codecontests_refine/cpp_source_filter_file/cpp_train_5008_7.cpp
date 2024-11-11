#include <bits/stdc++.h>
using namespace std;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
struct compare {
  bool operator()(const pair<long long, long long> a,
                  const pair<long long, long long> b) const {
    return a.first < b.first;
  }
};
long long n, m;
vector<long long> vert, store;
vector<long long> hori;
map<long long, vector<pair<long long, long long>>> mp;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0, x; i < n; i++) {
    cin >> x;
    vert.push_back(x);
  }
  for (long long i = 0, a, b, c; i < m; i++) {
    cin >> a >> b >> c;
    mp[c].push_back({a, b});
  }
  if (m == 0) {
    cout << 0 << "\n";
    exit(0);
  }
  vert.push_back(1e9);
  sort(vert.begin(), vert.end());
  store.resize(vert.size());
  long long ans = 0;
  for (auto &x : mp) {
    long long mn = 1e18, mx = -1;
    sort(x.second.begin(), x.second.end());
    long long flag = 0;
    for (long long i = 0; i < x.second.size(); i++) {
      if (i == 0) {
        if (x.second[0].first > 1) {
          hori.push_back(1);
          flag = 1;
          break;
        }
        continue;
      }
      if (x.second[i].first - x.second[i - 1].second >= 1) {
        hori.push_back(x.second[i - 1].second);
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      hori.push_back(x.second.rbegin()->second);
    }
  }
  m = hori.size();
  for (long long i : hori) {
    if (i == 1e9) {
      ans++;
      m--;
      continue;
    }
    auto temp = upper_bound(vert.begin(), vert.end(), i);
    auto index = temp - vert.begin();
    store[index]++;
  }
  for (long long i = 1; i < vert.size(); i++) {
    store[i] += store[i - 1];
  }
  long long res = 1e18;
  for (long long i = 0; i < vert.size(); i++) {
    res = min(res, ans + (m - store[i] + i));
  }
  cout << res << "\n";
}

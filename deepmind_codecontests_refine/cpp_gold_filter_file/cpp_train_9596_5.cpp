#include <bits/stdc++.h>
using namespace std;
const int MAX = 300006;
const long long MOD = 998244353LL;
long long fact[MAX] = {};
vector<pair<int, int> > v;
vector<int> v1, v2;
bool operator<(pair<int, int> x, pair<int, int> y) {
  if (x.first == y.first) {
    return x.second < y.second;
  }
  return x.first < y.first;
}
bool operator==(pair<int, int> x, pair<int, int> y) {
  return (x.first == y.first && x.second == y.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1LL;
  for (int i = 1; i < MAX; ++i) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    pair<int, int> x{a, b};
    v.push_back(x);
    v1.push_back(a);
    v2.push_back(b);
  }
  long long tot = fact[n], cnt1 = 1LL, cnt2 = 1LL, cnt12 = 0LL;
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  long long di = 1LL;
  for (int i = 1; i < v1.size(); ++i) {
    if (v1[i] != v1[i - 1]) {
      cnt1 *= fact[di];
      cnt1 %= MOD;
      di = 1LL;
    } else {
      ++di;
    }
  }
  cnt1 *= fact[di];
  cnt1 %= MOD;
  di = 1LL;
  for (int i = 1; i < v2.size(); ++i) {
    if (v2[i] != v2[i - 1]) {
      cnt2 *= fact[di];
      cnt2 %= MOD;
      di = 1LL;
    } else {
      ++di;
    }
  }
  cnt2 *= fact[di];
  cnt2 %= MOD;
  di = 1LL;
  bool rsort = 1;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i - 1].second > v[i].second) {
      rsort = 0;
    }
  }
  if (rsort) {
    cnt12 = 1LL;
    for (int i = 1; i < v1.size(); ++i) {
      if (v[i] == v[i - 1]) {
        ++di;
      } else {
        cnt12 *= fact[di];
        cnt12 %= MOD;
        di = 1LL;
      }
    }
    cnt12 *= fact[di];
    cnt12 %= MOD;
  }
  long long ans = tot - cnt1 - cnt2 + cnt12;
  ans = (ans + 10 * MOD) % MOD;
  cout << ans << endl;
}

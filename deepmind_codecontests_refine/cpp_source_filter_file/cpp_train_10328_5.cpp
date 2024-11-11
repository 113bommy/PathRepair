#include <bits/stdc++.h>
using namespace std;
int64_t getLog(int64_t a) {
  int r = 0;
  while (a > 0) {
    a /= 2;
    ++r;
  }
  return r - 1;
}
const int N = 61;
const int64_t mod = 998244353;
int64_t pw(int64_t a, int64_t b) {
  int64_t r = 1;
  while (b > 0) {
    if (b & 1) {
      r = r * a % mod;
    }
    a = a * a % mod;
    b /= 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<pair<int64_t, int64_t>> a, b;
  int na, nb;
  cin >> na;
  a.resize(na);
  for (int i = 0; i < na; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  cin >> nb;
  b.resize(nb);
  for (int i = 0; i < nb; ++i) {
    cin >> b[i].first >> b[i].second;
  }
  vector<int> ra[N], rb[N];
  for (auto [l, r] : a) {
    while (true) {
      int64_t nr = l | (l - 1);
      if (nr > r) {
        break;
      }
      ra[getLog(nr - l + 1)].push_back(l);
      l = nr + 1;
    }
    while (true) {
      int64_t nl = r & (r + 1);
      if (nl < l) {
        break;
      }
      ra[getLog(r - nl + 1)].push_back(nl);
      r = nl - 1;
    }
    assert(l == r + 1);
  }
  for (auto [l, r] : b) {
    while (true) {
      int64_t nr = l | (l - 1);
      if (nr > r) {
        break;
      }
      rb[getLog(nr - l + 1)].push_back(l);
      l = nr + 1;
    }
    while (true) {
      int64_t nl = r & (r + 1);
      if (nl < l) {
        break;
      }
      rb[getLog(r - nl + 1)].push_back(nl);
      r = nl - 1;
    }
    assert(l == r + 1);
  }
  vector<int64_t> ea, eb;
  vector<pair<int64_t, int64_t>> ans;
  for (int i = 0; i < 60; ++i) {
    for (int64_t j : ra[i]) {
      ea.push_back(j);
    }
    for (int64_t j : rb[i]) {
      eb.push_back(j);
    }
    for (int64_t& j : ea) {
      j = j & ~((1ll << i) - 1);
    }
    for (int64_t& j : eb) {
      j = j & ~((1ll << i) - 1);
    }
    sort(ea.begin(), ea.end());
    sort(eb.begin(), eb.end());
    ea.erase(unique(ea.begin(), ea.end()), ea.end());
    eb.erase(unique(eb.begin(), eb.end()), eb.end());
    for (int64_t j : ra[i]) {
      for (int64_t k : eb) {
        ans.emplace_back(j ^ k, j ^ k + (1ll << i) - 1);
      }
    }
    for (int64_t j : rb[i]) {
      for (int64_t k : ea) {
        ans.emplace_back(j ^ k, j ^ k + (1ll << i) - 1);
      }
    }
  }
  sort(ans.begin(), ans.end());
  int64_t last = 0;
  int64_t mn2 = pw(2, mod - 2);
  int64_t nans = 0;
  for (const auto& [l, r] : ans) {
    if (last >= r) continue;
    last = max(last + 1, l);
    nans =
        (nans + ((r + last) % mod * ((r - last + 1) % mod) % mod) * mn2 % mod) %
        mod;
    last = r;
  }
  cout << nans << endl;
  return 0;
}

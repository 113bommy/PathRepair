#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
int it = 0;
const ll mod = 998244353;
void solve(int k, int mask1, int mask2, bool bit) {
  int n1 = 1 << (k - 1);
  int n2 = n1;
  vector<int> left;
  vector<int> right;
  for (int i = 1; i <= n1; ++i) left.emplace_back(i);
  for (int i = n1 + 1; i <= n1 + n2; ++i) right.emplace_back(i);
  vector<int> cur = left;
  vector<int> nxt;
  vector<int> ans(1 << k, 1);
  int p = 0;
  int place = (1 << (k - 1)) + 1;
  for (int game = 0; game < n1 - 1; ++game) {
    if (!(mask1 & (1 << game))) {
      nxt.emplace_back(cur[p]);
      ans[cur[p + 1] - 1] = place;
    } else {
      nxt.emplace_back(cur[p + 1]);
      ans[cur[p] - 1] = place;
    }
    p += 2;
    if (p == cur.size()) {
      cur = nxt;
      nxt.clear();
      p = 0;
      place = (place + 1) >> 1;
    }
  }
  if (bit == 1) ans[cur[0] - 1] = 2;
  cur = right;
  p = 0;
  place = (1 << (k - 1)) + 1;
  nxt.clear();
  for (int game = 0; game < n1 - 1; ++game) {
    if (!(mask1 & (1 << game))) {
      nxt.emplace_back(cur[p]);
      ans[cur[p + 1] - 1] = place;
    } else {
      nxt.emplace_back(cur[p + 1]);
      ans[cur[p] - 1] = place;
    }
    p += 2;
    if (p == cur.size()) {
      cur = nxt;
      nxt.clear();
      p = 0;
      place = (place + 1) >> 1;
    }
  }
  if (bit == 0) ans[cur[0] - 1] = 2;
  for (int x : ans) cout << x << ' ';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int k;
  ll A, H;
  cin >> k >> A >> H;
  int max_place = 100;
  vector<ll> pA(max_place, 1);
  for (int i = 1; i < max_place; ++i) pA[i] = (pA[i - 1] * A) % mod;
  vector<int> left(1 << (k - 1));
  vector<int> right(1 << (k - 1));
  for (int i = 1; i <= (1 << (k - 1)); ++i) {
    left[i - 1] = i;
    right[i - 1] = (1 << (k - 1)) + i;
  }
  int n1 = left.size();
  int n2 = right.size();
  vector<pair<ll, int> > h1(1 << (n1 - 1));
  vector<pair<ll, int> > h2(1 << (n2 - 1));
  for (int mask = 0; mask < (1 << (n1 - 1)); ++mask) {
    vector<int> cur = left;
    vector<int> nxt;
    vector<int> lost;
    int p = 0;
    int place = (1 << (k - 1)) + 1;
    ll h = 0;
    for (int game = 0; game < n1 - 1; ++game) {
      if (!(mask & (1 << game))) {
        nxt.emplace_back(cur[p]);
        lost.emplace_back(cur[p + 1]);
      } else {
        nxt.emplace_back(cur[p + 1]);
        lost.emplace_back(cur[p]);
      }
      p += 2;
      if (p == cur.size()) {
        p = 0;
        cur.swap(nxt);
        nxt.clear();
        for (int x : lost) h = (h + x * pA[place]) % mod;
        lost.clear();
        place = (place + 1) >> 1;
      }
    }
    h1[mask] = {h, cur[0]};
  }
  for (int mask = 0; mask < (1 << (n2 - 1)); ++mask) {
    vector<int> cur = right;
    vector<int> nxt;
    vector<int> lost;
    int p = 0;
    int place = (1 << (k - 1)) + 1;
    ll h = 0;
    for (int game = 0; game < n2 - 1; ++game) {
      if (!(mask & (1 << game))) {
        nxt.emplace_back(cur[p]);
        lost.emplace_back(cur[p + 1]);
      } else {
        nxt.emplace_back(cur[p + 1]);
        lost.emplace_back(cur[p]);
      }
      p += 2;
      if (p == cur.size()) {
        p = 0;
        cur.swap(nxt);
        nxt.clear();
        for (int x : lost) h = (h + x * pA[place]) % mod;
        lost.clear();
        place = (place + 1) >> 1;
      }
    }
    h2[mask] = {h, cur[0]};
  }
  unordered_map<ll, int> mp1;
  unordered_map<ll, int> mp2;
  for (int mask = 0; mask < h2.size(); ++mask) {
    mp1[(h2[mask].first + pA[1] * h2[mask].second) % mod] = mask;
    mp2[(h2[mask].first + pA[2] * h2[mask].second) % mod] = mask;
  }
  for (int mask = 0; mask < h1.size(); ++mask) {
    ll H1 = (H - h1[mask].first - ((pA[1] * h1[mask].second) % mod) + 2 * mod) %
            mod;
    ll H2 = (H - h1[mask].first - ((pA[2] * h1[mask].second) % mod) + 2 * mod) %
            mod;
    if (mp1.count(H2)) {
      solve(k, mask, mp1[H2], 1);
      return 0;
    } else if (mp2.count(H1)) {
      solve(k, mask, mp2[H1], 0);
      return 0;
    }
  }
  cout << -1;
  return 0;
}

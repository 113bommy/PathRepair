#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 100;
const int INF = 1e9;
long long r(vector<int>& a) {
  if ((int)a.size() == 0) return 0LL;
  cout << "? " << a.size() << '\n';
  for (auto i : a) cout << i + 1 << ' ';
  cout << endl;
  long long ans;
  cin >> ans;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> msk;
  vector<vector<int>> req(13);
  for (int i = 0; i < (1 << 13); i++) {
    if (msk.size() >= n) break;
    if (__builtin_popcount(i) != 6) continue;
    msk.emplace_back(i);
    auto test = [](int x, int pos) { return (x >> pos) & 1; };
    for (int b = 0; b < 13; b++) {
      if (test(i, b)) req[b].emplace_back((int)msk.size() - 1);
    }
  }
  vector<long long> res;
  for (auto i : req) res.emplace_back(r(i));
  vector<long long> ans(n, 0);
  for (int i = 0; i < n; i++) {
    auto test = [](int x, int pos) { return (x >> pos) & 1; };
    for (int j = 0; j < 13; j++) {
      if (test(msk[i], j)) ans[i] |= res[j];
    }
  }
  cout << "! ";
  for (auto i : ans) cout << i << ' ';
  cout << '\n';
  return 0;
}

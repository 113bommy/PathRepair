#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
long long infll = 1e18 + 7;
long long n, ans = inf;
string s[N];
map<char, long long> mpp;
bool ck(vector<pair<long long, long long> > a, long long msk) {
  if (a.size() <= 1) return 1;
  if (msk == 0 && a.size() > 1) return 0;
  for (long long i = 0; i < 10; i++) {
    if (msk & (1 << i)) {
      vector<pair<long long, long long> > b, c;
      for (auto v : a) {
        if (v.first == i || v.second == i) {
          b.push_back(v);
        } else {
          c.push_back(v);
        }
      }
      return (ck(b, msk ^ (1 << i)) && ck(c, msk ^ (1 << i)));
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mpp['R'] = 0;
  mpp['G'] = 1;
  mpp['B'] = 2;
  mpp['Y'] = 3;
  mpp['W'] = 4;
  mpp['1'] = 5;
  mpp['2'] = 6;
  mpp['3'] = 7;
  mpp['4'] = 8;
  mpp['5'] = 9;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
  }
  sort(s + 1, s + 1 + n);
  s[0] = "A";
  vector<pair<long long, long long> > a;
  for (long long i = 1; i <= n; i++) {
    if (s[i] != s[i - 1]) {
      a.push_back({mpp[s[i][0]], mpp[s[i][1]]});
    }
  }
  for (long long msk = 1; msk < (1 << 10); msk++) {
    if (ck(a, msk)) {
      ans = min(ans, (long long)__builtin_popcountll(msk));
    }
  }
  cout << ans;
}

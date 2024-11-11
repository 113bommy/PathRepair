#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  out << '(' << p.first << ',' << p.second << ')';
  return out;
}
template <class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<vector<T>>& v) {
  for (vector<T>& x : v) out << x << '\n';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (T& x : v) out << x << ' ';
  return out;
}
long long gcd(long long a, long long b) {
  if (b > a) swap(a, b);
  return (b ? gcd(b, a % b) : a);
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = pair<pair<int, int>, int>;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
const int h = 1000000007;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.setstate(ios::failbit);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int mx = max({x, y, z});
    vl a(n);
    cin >> a;
    int st, sz;
    map<vvi, int> m;
    vvi dp(3, vi(1));
    for (int i = 1;; i++) {
      set<int> s;
      if (i - x > 0)
        s.insert(dp[0][i - x]);
      else
        s.insert(0);
      if (i - y > 0)
        s.insert(dp[1][i - y]);
      else
        s.insert(0);
      if (i - z > 0)
        s.insert(dp[2][i - z]);
      else
        s.insert(0);
      for (int j = 0; j < 4; j++)
        if (!s.count(j)) {
          dp[0].push_back(j);
          break;
        }
      s.clear();
      if (i - x > 0)
        s.insert(dp[0][i - x]);
      else
        s.insert(0);
      if (i - z > 0)
        s.insert(dp[2][i - z]);
      else
        s.insert(0);
      for (int j = 0; j < 4; j++)
        if (!s.count(j)) {
          dp[1].push_back(j);
          break;
        }
      s.clear();
      if (i - x > 0)
        s.insert(dp[0][i - x]);
      else
        s.insert(0);
      if (i - y > 0)
        s.insert(dp[1][i - y]);
      else
        s.insert(0);
      for (int j = 0; j < 4; j++)
        if (!s.count(j)) {
          dp[2].push_back(j);
          break;
        }
      if (i >= mx - 1) {
        vvi x{vi(dp[0].begin() + (i - mx + 1), dp[0].begin() + (i + 1)),
              vi(dp[1].begin() + (i - mx + 1), dp[1].begin() + (i + 1)),
              vi(dp[2].begin() + (i - mx + 1), dp[2].begin() + (i + 1))};
        if (m.count(x)) {
          st = m[x];
          sz = dp[0].size() - mx;
          break;
        }
        m[x] = i - mx + 1;
      }
    }
    int xr = 0;
    for (ll x : a) {
      if (x < sz)
        xr ^= dp[0][x];
      else
        xr ^= dp[0][st + (x - st) % (sz - st)];
    }
    int ans = 0;
    auto f = [&dp, &sz, &st](ll t, int i) {
      if (t < 0) return 0;
      if (t < sz)
        return dp[i][t];
      else
        return dp[i][st + (t - st) % (sz - st)];
      return -1;
    };
    for (ll t : a) {
      int mex = (t < sz ? dp[0][t] : dp[0][st + (t - st) % (sz - st)]);
      if (f(t - x, 0) == (mex ^ xr)) ans++;
      if (f(t - y, 1) == (mex ^ xr)) ans++;
      if (f(t - z, 2) == (mex ^ xr)) ans++;
    }
    cout << ans << '\n';
  }
}

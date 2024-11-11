#include <bits/stdc++.h>
using namespace std;
void doRoutine() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(322179);
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> a) {
  out << "[";
  for (int i = 0; i + 1 < a.size(); ++i) {
    out << a[i] << ", ";
  }
  if (!a.empty()) {
    out << a.back();
  }
  out << "]";
  return out;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << "{" << a.first << ", " << a.second << "}";
  return out;
}
const int MOD = 998244353;
int sum(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return (long long)a * b % MOD; }
int fpow(int a, int n) {
  return (n == 0
              ? 1
              : (n % 2 == 1 ? mul(a, fpow(a, n - 1)) : fpow(mul(a, a), n / 2)));
}
int rev(int a) { return fpow(a, MOD - 2); }
int divide(int a, int b) { return mul(a, rev(b)); }
int n;
const int MAXN = 55;
int dp[MAXN][MAXN][MAXN];
int sum_dp[MAXN][MAXN];
int getC(int n, int k) {
  int top = 1;
  int bot = 1;
  for (int i = 0; i < k; ++i) {
    top = mul(top, n - i);
    bot = mul(bot, i + 1);
  }
  return divide(top, bot);
}
int cnt(pair<int, int> seg, int s) {
  return getC(seg.second - seg.first + s, s);
}
bool inner(pair<int, int> s1, pair<int, int> s2) {
  return s2.first <= s1.first && s1.second <= s2.second;
}
signed main() {
  doRoutine();
  cin >> n;
  vector<pair<int, int> > arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }
  set<int> coords;
  for (auto e : arr) {
    coords.insert(e.first);
    coords.insert(e.second);
  }
  vector<int> coords_v;
  for (auto e : coords) {
    coords_v.push_back(e);
  }
  vector<pair<int, int> > segs;
  for (int i = 0; i < coords_v.size(); ++i) {
    segs.push_back({coords_v[i], coords_v[i]});
    if (i + 1 < coords_v.size() && coords_v[i] + 1 < coords_v[i + 1]) {
      segs.push_back({coords_v[i] + 1, coords_v[i + 1] - 1});
    }
  }
  for (int p = 1; p <= n; ++p) {
    for (int k = 0; k < segs.size(); ++k) {
      for (int s = 1; s <= p; ++s) {
        bool ok = true;
        for (int i = 0; i < s; ++i) {
          if (!inner(segs[k], arr[p - i - 1])) {
            ok = false;
          }
        }
        if (!ok) {
          dp[p][k][s] = 0;
          continue;
        }
        if (s == p) {
          dp[p][k][s] = cnt(segs[k], s);
        } else {
          int summ = 0;
          for (int k2 = k + 1; k2 < segs.size(); ++k2) {
            summ = sum(summ, sum_dp[p - s][k2]);
          }
          dp[p][k][s] = mul(cnt(segs[k], s), summ);
        }
      }
      sum_dp[p][k] = 0;
      for (int s = 0; s <= p; ++s) {
        sum_dp[p][k] = sum(sum_dp[p][k], dp[p][k][s]);
      }
    }
  }
  for (int p = 1; p <= n; ++p) {
    for (int k = 0; k < segs.size(); ++k) {
      for (int s = 1; s <= p; ++s) {
        if (0)
          cerr << "dp[" << p << "][" << k << "][" << s << "]: " << dp[p][k][s]
               << endl;
      }
    }
  }
  int res = 0;
  for (int k = 0; k < segs.size(); ++k) {
    for (int s = 1; s <= n; ++s) {
      res = sum(res, dp[n][k][s]);
    }
  }
  int div_by = 1;
  for (int i = 0; i < n; ++i) {
    div_by = mul(div_by, arr[i].second - arr[i].first + 1);
  }
  res = divide(res, div_by);
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double PI = acos(-1.0);
const long double EPS = 1e-10;
const int64_t INF = 1e18 + 10;
template <typename t>
t lcm(t a, t b) {
  return (a * b) / __gcd(a, b);
}
template <typename t>
t gcd(t a, t b) {
  return __gcd(a, b);
}
template <typename t>
t mul_mod(t a, t b, t m) {
  t res = ((a % m) * (b % m) % m);
  return res;
}
template <typename t>
t add_mod(t a, t b, t m) {
  t res = ((a % m) + (b % m)) % m;
  return res;
}
template <typename t>
t pow_mod(t a, t b, t m) {
  t res = 1;
  while (b) {
    if (b & 1) res = mul_mod(res, a, m);
    a = mul_mod(a, a, m), b >>= 1;
  }
  return res % m;
}
template <typename t>
vector<t> num_vec(t num) {
  t res;
  while (num) res.push_back(num % 10), num /= 10;
  return res;
}
template <typename t>
t vec_num(t vec) {
  t res = 0;
  long long mul = 1;
  for (long long i = 0; i < (int)vec.size(); i++) res = vec[i] * mul, mul *= 10;
  return res;
}
void solve(vector<vector<long long>>& con,
           vector<pair<long long, long long>>& prod, long long k, long long s) {
  long long n = (int)con[0].size(), m = (int)prod.size();
  long long lo = 0, hi = n - 1, d;
  auto check = [=](long long d) {
    vector<pair<long long, long long>> mn(
        2, make_pair(numeric_limits<long long>::max(), -1));
    for (long long i = 0; i < 2; i++) {
      mn[i] = make_pair(con[i][0], 0);
      for (long long j = 1; j < d + 1; j++) {
        if (mn[i].first > con[i][j]) mn[i] = make_pair(con[i][j], j);
      }
    }
    vector<pair<long long, pair<long long, long long>>> ans(m), res, t;
    for (long long i = 0; i < m; i++)
      ans[i] = make_pair(mn[prod[i].first - 1].first * prod[i].second,
                         make_pair(i + 1, mn[prod[i].first - 1].second + 1));
    sort(ans.begin(), ans.end(),
         [&](const pair<long long, pair<long long, long long>>& a,
             const pair<long long, pair<long long, long long>>& b) {
           return (a.first == b.first) ? (a.second.first < b.second.first)
                                       : (a.first < b.first);
         });
    long long cst = 0;
    for (long long i = 0; i < k; i++)
      cst += ans[i].first, res.emplace_back(ans[i]);
    return (cst <= k) ? res : t;
  };
  vector<pair<long long, pair<long long, long long>>> ans;
  while (lo <= hi) {
    long long mid = (lo + ((hi - lo) >> 1));
    auto temp = check(mid);
    if ((int)temp.size() >= k)
      ans = temp, d = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  bool ok = (int)ans.size() >= k;
  if (ok) {
    cout << d + 1 << endl;
    for (auto i : ans) cout << i.second.first << " " << i.second.second << endl;
  } else
    cout << -1 << endl;
}
int32_t main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  auto tstart = clock();
  long long n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<vector<long long>> con(2, vector<long long>(n));
  for (long long i = 0; i < 2; i++)
    for (long long j = 0; j < n; j++) cin >> con[i][j];
  vector<pair<long long, long long>> prod(m);
  for (long long i = 0; i < m; i++) cin >> prod[i].first >> prod[i].second;
  solve(con, prod, k, s);
  cerr << setprecision(2) << fixed
       << "Time elapsed: " << (double)(clock() - tstart) / CLOCKS_PER_SEC
       << endl;
  return 0;
}

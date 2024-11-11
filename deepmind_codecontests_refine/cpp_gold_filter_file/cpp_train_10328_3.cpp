#include <bits/stdc++.h>
using namespace std;
mt19937 rng(static_cast<unsigned int>(
    chrono::steady_clock::now().time_since_epoch().count()));
template <typename num_t>
inline void add_mod(num_t& a, const long long& b, const num_t& m) {
  a = (a + b) % m;
  if (a < 0) a += m;
}
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) {
  return a < b ? a = b, true : false;
}
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) {
  return a > b ? a = b, true : false;
}
template <typename num_t>
num_t gcd(const num_t& lhs, const num_t& rhs) {
  return !lhs ? rhs : gcd(rhs % lhs, lhs);
}
template <typename num_t>
num_t lcm(const num_t& lhs, const num_t& rhs) {
  return lhs / ::gcd(lhs, rhs) * rhs;
}
template <typename num_t>
num_t pw(num_t n, num_t k, const num_t& mod) {
  if (k == -1) k = mod - 2;
  num_t res = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res % mod;
}
const int inf = 1e9 + 7;
const int mod = 998244353;
const long long ll_inf = (long long)inf * inf * 9 + 7;
const int maxn = 1000 + 7;
const int base = 61;
vector<pair<long long, int>> get_nodes_from_range(long long lhs,
                                                  long long rhs) {
  vector<pair<long long, int>> ans;
  while (lhs <= rhs) {
    int j = 0;
    for (j = 0; j < base; ++j) {
      long long range = 1ll << j;
      long long nxt = lhs + range - 1;
      if (nxt <= rhs && (lhs >> j) == (nxt >> j)) {
      } else
        break;
    }
    ans.push_back({lhs, j - 1});
    --j;
    lhs += 1ll << j;
  }
  sort(ans.begin(), ans.end(),
       [&](const pair<long long, int>& u, const pair<long long, int>& v)
           -> bool { return u.second > v.second; });
  vector<pair<long long, int>> temp;
  for (int i = (0), _b = (10); i < _b; ++i) {
    if (i < ans.size()) {
      temp.push_back(ans[i]);
      if (ans.size() >= i + 1) temp.push_back(ans[(int)(ans).size() - i - 1]);
    }
  }
  return temp;
}
vector<vector<pair<long long, int>>> get_nodes_from_input() {
  int n;
  cin >> n;
  vector<vector<pair<long long, int>>> res;
  for (int i = (0), _b = (n); i < _b; ++i) {
    long long lhs, rhs;
    cin >> lhs >> rhs;
    vector<pair<long long, int>> temp = get_nodes_from_range(lhs, rhs);
    res.push_back(temp);
  }
  return res;
}
pair<long long, int> get_transform_node(pair<long long, int> lhs,
                                        pair<long long, int> rhs) {
  int bit_count = max(lhs.second, rhs.second);
  long long first_value = ((lhs.first ^ rhs.first) >> bit_count) << bit_count;
  return {first_value, bit_count};
}
long long sum(long long cur) {
  long long u = cur, v = cur + 1;
  if (u & 1)
    v >>= 1;
  else
    u >>= 1;
  if (u >= mod) u %= mod;
  if (v >= mod) v %= mod;
  return u * v % mod;
}
long long sum(long long u, long long v) {
  long long res = sum(v) - sum(u - 1);
  if (res < 0) res += mod;
  return res;
}
bool contain(pair<long long, int> out, pair<long long, int> in) {
  return out.first <= in.first &&
         out.first + (1ll << out.second) >= in.first + (1ll << in.second);
}
long long get_nxt(pair<long long, int> cur) {
  return cur.first + (1ll << cur.second) - 1;
}
void solve() {
  auto up = get_nodes_from_input();
  auto down = get_nodes_from_input();
  vector<pair<long long, int>> res;
  for (const auto& u : up)
    for (const auto& v : down) {
      for (auto p : u) {
        for (auto q : v) {
          auto temp = get_transform_node(p, q);
          res.push_back(temp);
        }
      }
    }
  sort(res.begin(), res.end());
  long long total = 0;
  for (int i = 0; i < (int)(res).size(); ++i) {
    long long cur = res[i].first;
    long long nxt = res[i].first + (1ll << res[i].second) - 1;
    while (i + 1 < res.size() && nxt >= res[i + 1].first) {
      ++i;
      update_max(nxt, res[i].first + (1ll << res[i].second) - 1);
    }
    total += sum(cur, nxt);
    if (total >= mod) total -= mod;
  }
  cout << total << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}

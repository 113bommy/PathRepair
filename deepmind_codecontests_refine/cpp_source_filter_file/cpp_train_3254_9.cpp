#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <typename T, size_t N>
int SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
int SIZE(const T &t) {
  return t.size();
}
string to_string(const string s, int x1 = 0, int x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) {
  string t = "";
  for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1);
       __iii__ <= __jjj__; ++__iii__) {
    t += b[__iii__] + '0';
  }
  return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);
int l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  l_v_l_v_l++;
  string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
  l_v_l_v_l--;
  return res;
}
template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords) {
  int rnk = rank<A>::value;
  string tab(t_a_b_s, ' ');
  string res = "";
  bool first = true;
  if (l_v_l_v_l == 0) res += '\n';
  res += tab + "[";
  x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
  auto l = begin(v);
  advance(l, x1);
  auto r = l;
  advance(r, (x2 - x1) + (x2 < SIZE(v)));
  for (auto e = l; e != r; e = next(e)) {
    if (!first) {
      res += ", ";
    }
    first = false;
    l_v_l_v_l++;
    if (e != l) {
      if (rnk > 1) {
        res += '\n';
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += '\n';
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cout << to_string(H) << " | ";
  dbgm(T...);
}
const long long MOD = (int)1e9 + 7;
const long long INF = 2e18 + 5;
struct hashLL {
  size_t operator()(long long x) const {
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return x;
  }
};
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long distsq(long long x1, long long y1, long long x2, long long y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
const int N = 100001;
long long n, m, k, t;
string s;
long long arr[4001];
bool dp[4001][1001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  memset(dp, 0, sizeof(dp));
  while (t--) {
    cin >> n;
    unordered_map<long long, long long> pos;
    long long prevpos = 2 * n;
    for (int i = 0; i < (2 * n); i++) {
      cin >> arr[i];
      pos[arr[i]] = i;
    }
    vector<long long> items;
    for (int i = 2 * n; i >= 1; i--) {
      long long idx = pos[i];
      if (idx >= prevpos) {
        continue;
      }
      long long wt = prevpos - idx;
      items.push_back(wt);
      prevpos = min(prevpos, idx);
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) dp[0][i] = false;
    for (int i = 1; i <= items.size(); i++) {
      dp[i][0] = true;
    }
    for (int i = 0; i < items.size(); i++) {
      int item = items[i];
      for (int wt = 1; wt <= n; wt++) {
        if (wt - item >= 0) {
          dp[i + 1][wt] = dp[i][wt - item] || dp[i][wt];
        } else {
          dp[i + 1][wt] = dp[i][wt];
        }
      }
    }
    if (dp[items.size()][n])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const long long int MOD = 1e9 + 696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;
template <class T>
int size(T &&x) {
  return int(x.size());
}
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &p) {
  return out << '(' << p.first << ", " << p.second << ')';
}
template <class T>
auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
  out << '{';
  for (auto it = x.begin(); it != x.end(); ++it)
    out << *it << (it == prev(x.end()) ? "" : ", ");
  return out << '}';
}
void dump() {}
template <class T, class... Args>
void dump(T &&x, Args... args) {
  cerr << x << ";  ";
  dump(args...);
}
mt19937_64 rng(0);
int random(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
const int maxn = 1010000;
int n, m, k;
inline void addmod(int &x, int val) {
  x += val;
  while (x >= mod) x -= mod;
}
vector<long long> pots[40];
int clz(unsigned long long N) { return N ? 63 - __builtin_clzll(N) : 0; }
long long tab[40];
int dp[20][(1 << 17)];
int ndp[20][(1 << 17)];
long long res[40];
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  cin >> n >> m;
  long long zeros = 0;
  for (int i = (1); i <= (n); ++i) {
    long long val;
    cin >> val;
    if (val == 0)
      ++zeros;
    else {
      int x = clz(val);
      pots[x].push_back(val);
    }
  }
  for (int bit = 38; bit >= 0; --bit) {
    if (pots[bit].size() > 1) {
      for (int j = 1; j < (int)pots[bit].size(); ++j) {
        long long new_value = (pots[bit][0] ^ pots[bit][j]);
        if (new_value == 0)
          ++zeros;
        else
          pots[clz(new_value)].push_back(new_value);
      }
    }
  }
  for (int bit = (0); bit <= (37); ++bit)
    if (!pots[bit].empty())
      tab[bit] = pots[bit][0];
    else
      tab[bit] = -1;
  long long sc = 1;
  for (int i = (1); i <= (zeros); ++i) sc = sc * 2LL % mod;
  int pod = 17;
  int mx = 36;
  int LEN = mx - pod;
  int PW = (1 << LEN);
  int KEY_NUMBER = (1 << 17) - 1;
  for (int i = 0; i < PW; ++i) {
    long long ksor = 0;
    bool fail = false;
    for (int j = 17; j < 36; ++j) {
      if (i & (1 << (j - 17))) {
        if (tab[j] == -1)
          fail = true;
        else
          ksor ^= tab[j];
      }
    }
    if (!fail) {
      int sm = 0;
      for (int j = 17; j < 36; ++j)
        if (i & (1LL << j)) sm++;
      dp[sm][ksor & KEY_NUMBER]++;
    }
  }
  int pt = (1 << 17);
  for (int i = 0; i < 17; ++i)
    if (tab[i] != -1) {
      for (int sz = 0; sz < 20; ++sz)
        for (int num = 0; num < pt; ++num) ndp[sz][num] = dp[sz][num];
      for (int sz = 0; sz < 20; ++sz)
        for (int num = 0; num < pt; ++num)
          addmod(ndp[sz][num ^ tab[i]], dp[sz][num]);
      for (int sz = 0; sz < 20; ++sz)
        for (int num = 0; num < pt; ++num) dp[sz][num] = ndp[sz][num];
    }
  for (int sz = 0; sz < 20; ++sz)
    for (int num = 0; num < pt; ++num)
      res[sz + __builtin_popcount(num)] += dp[sz][num];
  for (int i = 0; i <= m; ++i) cout << res[i] * sc % mod << ' ';
}

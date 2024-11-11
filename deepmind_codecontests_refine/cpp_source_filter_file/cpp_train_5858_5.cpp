#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int nax = 2e4 + 10;
const int mod = 1e9 + 7;
int p[2] = {31, 37};
long long inv[2][nax], POW[2][nax];
long long Pow(long long a, long long b) {
  if (!b) return 1;
  long long ret = Pow(a, b / 2);
  if (b % 2) return ((ret * ret) % mod * a) % mod;
  return (ret * ret) % mod;
}
void init() {
  POW[0][0] = POW[1][0] = 1;
  inv[0][0] = inv[1][0] = Pow(POW[0][0], mod - 2);
  for (int i = 1; i < nax; i++) {
    for (int x = 0; x < 2; x++) {
      POW[x][i] = (POW[x][i - 1] * p[x]) % mod;
      inv[x][i] = Pow(POW[x][i], mod - 2);
    }
  }
}
struct HASH {
  vector<long long> sum[2];
  void init(int n) {
    sum[0].resize(n + 1);
    sum[1].resize(n + 1);
  }
  void build(string s) {
    for (int i = 0; i < s.size(); i++) {
      for (int x = 0; x < 2; x++) {
        sum[x][i + 1] = ((s[i] - 'a' + 1) * POW[x][i]) % mod;
        sum[x][i + 1] = (sum[x][i + 1] + sum[x][i]) % mod;
      }
    }
  }
  pair<long long, long long> check(int l, int r) {
    long long h1 = ((sum[0][r + 1] - sum[0][l] + mod) % mod * inv[0][l]) % mod;
    long long h3 = ((sum[1][r + 1] - sum[1][l] + mod) % mod * inv[1][l]) % mod;
    return {h1, h3};
  }
  bool check(int l1, int r1, int l2, int r2) {
    long long h1 =
        ((sum[0][r1 + 1] - sum[0][l1] + mod) % mod * inv[0][l1]) % mod;
    long long h2 =
        ((sum[0][r2 + 1] - sum[0][l2] + mod) % mod * inv[0][l2]) % mod;
    long long h3 =
        ((sum[1][r1 + 1] - sum[1][l1] + mod) % mod * inv[1][l1]) % mod;
    long long h4 =
        ((sum[1][r2 + 1] - sum[1][l2] + mod) % mod * inv[1][l2]) % mod;
    return h1 == h2 && h3 == h4;
  }
};
struct BIT {
  vector<long long> tree;
  int n;
  void init(int N) {
    n = N;
    tree = vector<long long>(n + 1, 0);
  }
  void update(int x, long long val) {
    val %= mod;
    while (x <= n) {
      tree[x] += val;
      tree[x] %= mod;
      if (tree[x] < 0) tree[x] += mod;
      x += x & (-x);
    }
  }
  long long get(int x) {
    long long res = 0;
    while (x) {
      res += tree[x];
      res %= mod;
      if (res < 0) res += mod;
      x -= x & (-x);
    }
    return res;
  }
  long long get(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
  }
};
vector<HASH> h;
BIT t[2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int n;
  cin >> n;
  h.resize(n);
  vector<pair<int, int>> g;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    h[i].init(s[i].size() + 1);
    for (int j = 0; j < s[i].size(); j++) {
      g.push_back({i, j});
    }
    g.push_back({i, s[i].size()});
    h[i].build(s[i]);
  }
  auto get = [&](pair<int, int> a, int md) {
    pair<long long, long long> val;
    if (a.second <= md) {
      if (a.second)
        val = h[a.first].check(0, a.second - 1);
      else
        val = {0, 0};
      pair<long long, long long> tmp = h[a.first].check(a.second + 1, md + 1);
      val.first = (val.first + (tmp.first * POW[0][a.second]) % mod) % mod;
      val.second = (val.second + (tmp.second * POW[1][a.second]) % mod) % mod;
    } else {
      val = h[a.first].check(0, md);
    }
    return val;
  };
  sort((g).begin(), (g).end(), [&](pair<int, int> a, pair<int, int> b) {
    int lo = 0,
        hi = min(s[a.first].size() - (a.second != s[a.first].size()),
                 s[b.first].size() - (b.second != s[b.first].size())) -
             1,
        ans = -1;
    while (lo <= hi) {
      int md = (lo + hi) / 2;
      pair<long long, long long> vala = get(a, md), valb = get(b, md);
      if (vala == valb) {
        lo = md + 1;
        ans = md;
      } else {
        hi = md - 1;
      }
    }
    ans++;
    if (ans + (ans >= a.second) == s[a.first].size() &&
        ans + (ans >= b.second) == s[b.first].size())
      return a.first < b.first;
    if (ans + (ans >= a.second) == s[a.first].size()) return true;
    if (ans + (ans >= b.second) == s[b.first].size()) return false;
    char x = s[a.first][ans + (ans >= a.second)];
    char y = s[b.first][ans + (ans >= b.second)];
    return x < y;
  });
  vector<vector<int>> at(n);
  for (int i = 0; i < g.size(); i++) {
    at[g[i].first].push_back(i + 1);
  }
  t[0].init(g.size());
  t[1].init(g.size());
  for (int i : at[0]) {
    t[0].update(i, 1);
  }
  for (int i = 1; i < n; i++) {
    long long ans = 0;
    int bit = i % 2;
    for (int j : at[i]) {
      t[bit].update(j, t[!bit].get(j));
    }
    for (int j : at[i - 1]) {
      t[!bit].update(j, -t[!bit].get(j));
    }
  }
  cout << t[!(n % 2)].get(g.size()) << '\n';
}

#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  precalc();
  while (t--) {
    solve(true);
  }
  cout.flush();
  return 0;
}
template <typename T>
T binpow(T q, T w, T mod) {
  if (!w) return 1 % mod;
  if (w & 1) return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}
template <typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template <typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}
template <typename T>
void make_unique(vector<T>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}
template <typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}
mt19937 rng(
    (unsigned long long)chrono::steady_clock::now().time_since_epoch().count());
void precalc() {}
const li mod = 998244353;
const li L = 21;
const li N = (1 << L);
bool fft_initialized = false;
using Poly = vector<long long>;
long long pw(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1ll) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
li getRoot() {
  li root = 1;
  while (pw(root, 1 << L) != 1 || pw(root, 1 << (L - 1)) == 1) {
    ++root;
  }
  return root;
}
const li root = getRoot();
long long angles[N + 1];
li bitrev[N];
void fft_init() {
  if (fft_initialized) {
    return;
  }
  angles[0] = 1;
  for (li i = 1; i <= N; ++i) {
    angles[i] = angles[i - 1] * root % mod;
  }
  for (li i = 0; i < N; ++i) {
    li x = i;
    for (li j = 0; j < L; ++j) {
      bitrev[i] = (bitrev[i] << 1) | (x & 1);
      x >>= 1;
    }
  }
  fft_initialized = true;
}
inline li revBit(li x, li len) { return bitrev[x] >> (L - len); }
void fft(vector<long long>& a, bool inverse = false) {
  assert(fft_initialized && "you fucking cunt just write fft_init()");
  li n = a.size();
  assert(!(n & (n - 1)));
  li l = __builtin_ctz(n);
  for (li i = 0; i < n; ++i) {
    li j = revBit(i, l);
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (li len = 1; len < n; len *= 2) {
    for (li start = 0; start < n; start += 2 * len) {
      for (li i = 0; i < len; ++i) {
        long long x = a[start + i], y = a[start + len + i];
        li idx = N / 2 / len * i;
        long long w = angles[inverse ? N - idx : idx];
        w = w * y % mod;
        a[start + i] = x + w;
        if (a[start + i] >= mod) {
          a[start + i] -= mod;
        }
        a[start + len + i] = x - w;
        if (a[start + len + i] < 0) {
          a[start + len + i] += mod;
        }
      }
    }
  }
  if (inverse) {
    li rev_deg = 1;
    for (li i = 0; i < l; ++i) {
      rev_deg = (rev_deg % 2) ? ((rev_deg + mod) / 2) : (rev_deg / 2);
    }
    for (auto& x : a) {
      x = x * rev_deg % mod;
    }
  }
}
Poly multiply(Poly a, Poly b) {
  li n = 1;
  while (n < (li)a.size() || n < (li)b.size()) {
    n *= 2;
  }
  a.resize(n + n);
  b.resize(n + n);
  fft(a);
  fft(b);
  for (li i = 0; i < n + n; ++i) {
    a[i] = a[i] * b[i] % mod;
  }
  fft(a, true);
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
  return a;
}
void add(li& cur, li val) { cur = (cur + val) % mod; }
Poly sum(Poly a, Poly b) {
  Poly res(max(a.size(), b.size()), 0);
  for (li i = 0; i < res.size(); ++i) {
    if (i < a.size()) {
      add(res[i], a[i]);
    }
    if (i < b.size()) {
      add(res[i], b[i]);
    }
  }
  return res;
}
map<li, Poly> dp;
Poly get_res(li n) {
  if (dp.count(n)) {
    return dp[n];
  }
  dp[n] = {};
  if (n < 0) {
    return dp[n];
  }
  if (n <= 1) {
    return dp[n] = {1};
  }
  if (n == 2) {
    return dp[n] = {1, 1};
  }
  li half = n / 2;
  auto f = get_res(half);
  auto s = get_res(n - half);
  dp[n] = multiply(f, s);
  f = get_res(half - 1);
  s = get_res(n - half - 1);
  auto cur_vec = multiply(f, s);
  cur_vec.insert(cur_vec.begin(), 0);
  dp[n] = sum(dp[n], cur_vec);
  return dp[n];
}
const li C = 5500;
li fact[C];
li revfact[C];
li getA(li n, li k) { return fact[n] * revfact[n - k] % mod; }
void solve(__attribute__((unused)) bool read) {
  if (fact[0] == 0) {
    fact[0] = 1;
    for (li i = 1; i < C; ++i) {
      fact[i] = fact[i - 1] * i % mod;
    }
    revfact[C - 1] = binpow(fact[C - 1], mod - 2, mod);
    for (li i = C - 2; i >= 0; --i) {
      revfact[i] = revfact[i + 1] * (i + 1) % mod;
    }
  }
  dp.clear();
  fft_init();
  vector<vector<li>> used(2);
  li h, w;
  if (read) {
    cin >> h >> w;
  } else {
    h = 3600;
    w = 3600;
  }
  used[0].resize(h);
  used[1].resize(w);
  li N;
  if (read) {
    cin >> N;
  } else {
    N = 2400;
  }
  for (li i = 0; i < N; ++i) {
    for (li j = 0; j < 2; ++j) {
      li r, c;
      if (read) {
        cin >> r >> c;
        --r;
        --c;
      } else {
        r = rand() % h;
        c = rand() % w;
      }
      used[0][r] = true;
      used[1][c] = true;
    }
  }
  vector<vector<li>> lens(2);
  map<li, Poly> results;
  for (li i = 0; i < 2; ++i) {
    for (li j = 0; j < used[i].size();) {
      li r = j;
      while (r < used[i].size() && used[i][r] == 0) {
        ++r;
      }
      if (r > j) {
        lens[i].push_back(r - j);
      }
      j = r + 1;
    }
  }
  for (auto& vec : lens) {
    for (li x : vec) {
      if (results.count(x)) {
        continue;
      }
      results[x] = get_res(x);
    }
  }
  vector<Poly> actual_results(2);
  vector<li> actual_sum(2);
  for (li i = 0; i < 2; ++i) {
    multiset<pair<li, Poly>> cur_set;
    for (li x : lens[i]) {
      cur_set.insert({x, results[x]});
    }
    if (cur_set.empty()) {
      cout << 0 << endl;
      return;
    }
    while (cur_set.size() > 1) {
      auto item1 = *cur_set.begin();
      cur_set.erase(cur_set.begin());
      auto item2 = *cur_set.begin();
      cur_set.erase(cur_set.begin());
      pair<li, Poly> new_item = {item1.first + item2.first,
                                 multiply(item1.second, item2.second)};
      cur_set.insert(new_item);
    }
    actual_sum[i] = cur_set.begin()->first;
    actual_results[i] = cur_set.begin()->second;
  }
  li res = 0;
  for (li take1 = 0; take1 < actual_results[0].size(); ++take1) {
    for (li take2 = 0; take2 < actual_results[1].size(); ++take2) {
      li rest1 = actual_sum[1] - 2 * take2;
      li rest2 = actual_sum[0] - 2 * take1;
      if (rest1 < take1 || rest2 < take2) {
        continue;
      }
      li cur_mult = getA(rest1, take1) * getA(rest2, take2) % mod *
                    actual_results[0][take1] % mod * actual_results[1][take2] %
                    mod;
      add(res, cur_mult);
    }
  }
  cout << res << endl;
}

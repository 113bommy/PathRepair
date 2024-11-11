#include <bits/stdc++.h>
using namespace std;
auto start = std::chrono::system_clock::now();
inline void skj() {
  std::chrono::time_point<std::chrono::system_clock> end;
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  cerr << "Time taken " << elapsed_seconds.count() * 1000 << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
inline long long binexp(long long a, long long b, long long m) {
  if (a == 0) {
    return 0;
  }
  long long res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = (res * 1ll * a) % m;
    a = (a * 1ll * a) % m;
    b >>= 1;
  }
  return res;
}
inline long long binmul(long long a, long long b, long long m) {
  a %= m;
  long long res = 0;
  while (b) {
    if (b & 1) {
      res = (res + a) % m;
    }
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
const long long N = 2e5 + 5;
long long seg[4 * N], lazy[4 * N];
long long preSum[N];
inline void build(long long i, long long s, long long e) {
  if (s == e) {
    seg[i] = preSum[s];
  } else {
    long long mid = (s + e) >> 1, p = i << 1, q = p | 1;
    build(p, s, mid);
    build(q, mid + 1, e);
    seg[i] = min(seg[p], seg[q]);
  }
}
void updateRange(long long node, long long start, long long end, long long l,
                 long long r, long long val) {
  if (lazy[node] != 0) {
    seg[node] += lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start > end or start > r or end < l) return;
  if (start >= l and end <= r) {
    seg[node] += val;
    if (start != end) {
      lazy[node * 2] += val;
      lazy[node * 2 + 1] += val;
    }
    return;
  }
  long long mid = (start + end) / 2;
  updateRange(node * 2, start, mid, l, r, val);
  updateRange(node * 2 + 1, mid + 1, end, l, r, val);
  seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}
long long queryRange(long long node, long long start, long long end,
                     long long l, long long r) {
  if (start > end or start > r or end < l) return 0;
  if (lazy[node] != 0) {
    seg[node] += lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (start >= l and end <= r) return seg[node];
  long long mid = (start + end) / 2;
  long long p1 = queryRange(node * 2, start, mid, l, r);
  long long p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
  return min(p1, p2);
}
inline void solve_me_senpai() {
  long long n;
  cin >> n;
  vector<long long> p(n), c(n), ic(n + 1, 0ll);
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> c[i];
    ic[p[i]] = c[i];
  }
  for (long long i = 1; i <= n; i++) {
    preSum[i] = preSum[i - 1] + ic[i];
  }
  build(1, 1, n);
  long long ans = 1e15;
  for (long long i = 0; i < n - 1; i++) {
    if (p[i] != 1) {
      updateRange(1, 1, n, 1, p[i] - 1, c[i]);
    }
    updateRange(1, 1, n, p[i], n, -c[i]);
    ans = min(ans, queryRange(1, 1, n, 1, n));
  }
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  long long a = 1;
  while (t--) {
    solve_me_senpai();
    a++;
  }
  return 0;
}

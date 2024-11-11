#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long fp(long long a, long long b) {
  if (b == 0) return 1;
  long long x = fp(a, b / 2);
  x = (x * x) % mod;
  if (b & 1) x = (x * a) % mod;
  return x;
}
auto random_address = [] {
  char *p = new char;
  delete p;
  return uint64_t(p);
};
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() *
                      (random_address() | 1);
mt19937_64 rng(SEED);
const long long N = 5e5 + 5;
long long pw1[N];
long long prime1 = 107, prime2 = 97;
struct node {
  long long x1;
  node() { x1 = 0; }
};
node merge(node a, node b) {
  node c;
  c.x1 = a.x1 + b.x1;
  if (c.x1 >= mod) c.x1 -= mod;
  return c;
}
vector<node> bit(4 * N);
void build(long long id, long long l, long long r) {
  if (l == r) {
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  bit[id] = merge(bit[2 * id], bit[2 * id + 1]);
}
node get(long long id, long long l, long long r, long long L, long long R) {
  if (R < l || r < L) {
    node c;
    return c;
  }
  if (L <= l && r <= R) {
    return bit[id];
  }
  long long mid = (l + r) / 2;
  return merge(get(2 * id, l, mid, L, R), get(2 * id + 1, mid + 1, r, L, R));
}
void upd(long long id, long long l, long long r, long long L, long long R,
         long long v) {
  if (R < l || r < L) return;
  if (L <= l && r <= R) {
    bit[id].x1 = (v * pw1[L]) % mod;
    return;
  }
  long long mid = (l + r) / 2;
  upd(2 * id, l, mid, L, R, v);
  upd(2 * id + 1, mid + 1, r, L, R, v);
  bit[id] = merge(bit[2 * id], bit[2 * id + 1]);
}
void solve() {
  map<long long, long long> mp1, freq, freq2;
  long long n, ans = 0;
  cin >> n;
  deque<long long> q[n + 1];
  long long a[n + 1];
  mp1[0]++;
  vector<long long> in(n + 1);
  in[0] = 0;
  long long j = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    q[a[i]].push_back(i);
    freq[a[i]]++;
    freq2[a[i]]++;
    long long f = freq[a[i]];
    if (freq2[a[i]] >= 4) {
      long long z = q[a[i]].front();
      while (j < z) {
        mp1[in[j]]--;
        j++;
        freq2[a[j]]--;
        q[a[j]].pop_front();
      }
    }
    upd(1, 1, n, a[i], a[i], f % 3);
    long long x = get(1, 1, n, 1, n).x1;
    ans += mp1[x];
    mp1[x]++;
    in[i] = x;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(0));
  long long t;
  t = 1;
  pw1[0] = 1;
  for (long long i = 1; i < N; i++) {
    pw1[i] = (rng()) % mod;
  }
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}

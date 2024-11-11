#include <bits/stdc++.h>
using namespace std;
const long long INFL = 1LL << 60;
const int INF = 1 << 30;
long long MOD = 1000000007;
vector<long long> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
vector<long long> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};
void pres(double A, long long x = 10) {
  cout << fixed << setprecision(x) << A << endl;
}
void BinarySay(long long x, long long y = 60) {
  for (long long i = 0; i < (y); i++) cout << (x >> (y - 1 - i) & 1);
  cout << endl;
}
long long cnt_bit(long long x) { return __builtin_popcountll(x); }
long long pow_long(long long x, long long k) {
  long long res = 1;
  while (k > 0) {
    if (k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}
long long pow_mod(long long x, long long k) {
  long long res = 1;
  while (k > 0) {
    if (k % 2) {
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    k /= 2;
  }
  return res;
}
long long inverse(long long x) { return pow_mod(x, MOD - 2); };
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; };
void solve() {
  long long N, K;
  cin >> N >> K;
  vector<long long> P(N), Q(N);
  for (long long i = 0; i < (N); i++) {
    cin >> P[i];
    P[i]--;
  }
  for (long long i = 0; i < (N); i++) {
    cin >> Q[i];
    Q[i]--;
  }
  vector<long long> posb(N);
  for (long long i = 0; i < (N); i++) posb[Q[i]] = i;
  vector<long long> A(N);
  for (long long i = 0; i < (N); i++) {
    A[posb[P[i]]] = Q[i];
  }
  vector<long long> pos(N);
  for (long long i = 0; i < (N); i++) {
    pos[A[i]] = i;
  }
  long long right = -INFL;
  set<pair<long long, long long>> seg;
  for (long long i = 0; i < (N); i++) {
    long long pi = pos[i];
    right = max(right, pi);
    seg.insert({pi, right});
  }
  long long now = 0;
  set<long long> queue;
  vector<char> ans(N);
  for (long long i = 0; i < (N); i++) {
    if (queue.empty()) {
      now++;
    }
    if (now >= K) now = K;
    ans[P[i]] = (char)('a' + now - 1);
    while (!seg.empty() && seg.begin()->first == i) {
      pair<long long, long long> p = *seg.begin();
      seg.erase(p);
      queue.insert(p.second);
    }
    queue.erase(i);
  }
  if (now < K) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (long long i = 0; i < (N); i++) {
    cout << ans[i];
  }
  cout << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
const long long int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
struct custom {
  bool operator()(const pair<int, pair<int, int> > &p1,
                  const pair<int, pair<int, int> > &p2) const {
    return p1.first < p2.first;
  }
};
long long int get_pow(long long int a, long long int b, long long int M = MOD) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
const long long int N = 3e5 + 5, inf = 2e18;
struct fenwick {
 public:
  long long int A[N];
  long long int query(int idx) {
    long long int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx) ret += A[idx];
    return ret;
  }
  void _update(int idx, long long int val) {
    for (++idx; idx < N; idx += idx & -idx) A[idx] += val;
  }
  void range_update(int l, int r, long long int val) {
    _update(l, val);
    _update(r + 1, -val);
  }
};
fenwick fen;
vector<long long> v;
long long int n, k;
bool check(long long int lim) {
  for (long long int i = (long long int)0; i < (long long int)(n + 3); i++)
    fen.A[i] = 0;
  fen.range_update(0, 0, 1);
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    if (fen.query(i)) {
      long long int up = i + k;
      long long int it =
          upper_bound(v.begin(), v.end(), v[i] + lim) - v.begin();
      it = min(it, n);
      if (it >= up) fen.range_update(up, it, 1);
    }
  }
  return fen.query(n) > 0;
}
void solve() {
  cin >> n >> k;
  v.resize(n);
  for (long long int i = (long long int)0; i < (long long int)(n); i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  long long int lo = -1, hi = 1e9;
  while (lo + 1 < hi) {
    long long int m = (lo + hi) >> 1;
    if (check(m))
      hi = m;
    else
      lo = m;
  }
  cout << hi << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  clock_t z = clock();
  for (long long int tes = (long long int)0; tes < (long long int)(test);
       tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}

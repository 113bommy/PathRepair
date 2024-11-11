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
  bool operator()(const pair<long long int, long long int> &p1,
                  const pair<long long int, long long int> &p2) const {
    if (p1.second == p2.second) {
      return p1.first < p2.first;
    }
    return p1.second > p2.second;
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
const long long int N = 2e5 + 5, inf = 2e18;
void solve() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> v(n);
  int u = 0, d = n, x;
  for (long long int i = (long long int)0; i < (long long int)(m); i++) {
    cin >> x;
    int r = -1;
    for (long long int i = (long long int)0; i < (long long int)(u); i++) {
      if (v[i] > x) {
        r = i;
        break;
      }
    }
    if (r == -1) {
      for (int j = n - 1; j > d; j--) {
        if (v[j] < x) {
          r = j;
          break;
        }
      }
      if (r == -1) {
        if (x <= c / 2)
          r = u++;
        else
          r = --d;
      }
    }
    cout << r + 1 << endl;
    v[r] = x;
    if (u == d) break;
  }
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

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
const long long int N = 5e5 + 5, inf = 2e18;
long long int ans, n;
long long int have[18];
void pre() {
  have[1] = 1;
  have[3] = 18;
  have[5] = 1800;
  have[7] = 670320;
  have[9] = 734832000;
  have[11] = 890786230;
  have[13] = 695720788;
  have[15] = 150347555;
}
void solve() {
  pre();
  cin >> n;
  cout << have[n];
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

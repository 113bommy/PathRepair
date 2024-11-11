#include <bits/stdc++.h>
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
  bool operator()(
      const pair<long long int, pair<long long int, long long int> > &p1,
      const pair<long long int, pair<long long int, long long int> > &p2)
      const {
    if (p1.first == p2.first) return true;
    return p1.first < p2.first;
  }
};
long long int get_pow(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
const long long int N = 1e5 + 5, inf = 4e18;
void solve() {
  long long int k;
  cin >> k;
  long long int lo = 1, hi = 1e12;
  while (lo + 1 < hi) {
    long long int mid = (lo + hi) / 2;
    long long int z = 1, tot = 0, p = 0, x = mid, d = 0;
    while (z * 10 < mid) {
      p++;
      tot += (z * 10 - z) * p;
      z = z * 10;
    }
    while (x > 0) {
      x = x / 10;
      d++;
    }
    tot += (mid - z + 1) * (p + 1);
    if (tot < k) {
      lo = mid;
    } else if (tot - d >= k) {
      hi = mid;
    } else {
      x = mid;
      while (tot > k) {
        tot--;
        x = x / 10;
      }
      cout << x % 10 << '\n';
      return;
    }
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

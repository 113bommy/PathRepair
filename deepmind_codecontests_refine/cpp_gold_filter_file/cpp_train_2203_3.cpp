#include <bits/stdc++.h>
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
const long long int MOD = 1e12 + 7;
struct custom {
  bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
    return p1.first > p2.first;
  }
};
long long int get_pow(long long int x, long long int k) {
  if (k == 0) return 1ll;
  long long int y = get_pow(x, k / 2);
  y = (y * y) % MOD;
  if (k % 2) y = (y * x) % MOD;
  return y;
}
const int N = 3e5 + 50;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = (int)0; i < int(n); i++) {
    cin >> a[i];
  }
  long long int dist = MOD, ans = a[0];
  for (int i = (int)0; i < int(n - k + 1); i++) {
    if (i + k >= n) break;
    if (dist > a[i + k] - a[i]) {
      dist = a[i + k] - a[i];
      ans = (a[i] + a[i + k]) / 2;
    }
  }
  print(ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  cin >> test;
  clock_t z = clock();
  for (int tes = (int)0; tes < int(test); tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}

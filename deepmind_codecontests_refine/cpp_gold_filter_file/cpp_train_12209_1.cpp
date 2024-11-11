#include <bits/stdc++.h>
using namespace std;
void debug_out() { cout << ']' << '\n'; }
template <typename T, typename... R>
void debug_out(const T &ff, const R &...rr) {
  cout << ff;
  if (sizeof...(R)) {
    cout << ", ";
  }
  debug_out(rr...);
}
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int mpow(int base, int exp);
template <class T>
T npow(T base, T exp);
const int mod = 1e9 + 7;
const int N = 3e5, M = N;
void Solve_main() {
  int n, m, k;
  int i, j;
  int temp = 1;
  cin >> n >> k;
  vector<int> res(n);
  for (i = (0); i < (n); ++i) {
    cin >> m;
    if (!(k & 1) && m == (k >> 1)) {
      res[i] = temp;
      temp = 1 - temp;
    } else if (m > (k >> 1)) {
      res[i] = 1;
    } else {
      res[i] = 0;
    }
  }
  for (i = 0; i < ((int)(res).size()); i++) {
    cout << res[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int tc = 1;
  cin >> tc;
  while (tc--) {
    Solve_main();
  }
  cerr << "[time:" << 1.0 * clock() / CLOCKS_PER_SEC << "s] ";
  return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
template <class T>
T npow(T base, T exp) {
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}

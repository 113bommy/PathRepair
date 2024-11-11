#include <bits/stdc++.h>
using namespace std;
template <typename T>
void emilia_mata_tenshi(const char *s, T l, T r) {
  cerr << "\e[1;33m" << s << " = [";
  while (l != r) {
    cerr << *l;
    cerr << (++l == r ? ']' : ',');
  }
  cerr << "\e[0m\n";
}
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS = 1e-7;
const int INF = 0x3F3F3F3F;
const ll LINF = 4611686018427387903;
const int MOD = 1e9 + 7;
static int Lamy_is_cute = []() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  return 48763;
}();
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int it = 0;
    while (k--) {
      for (int i = 0; i < m - n % m; i++) {
        cout << n / m << ' ';
        for (int j = 0; j < n / m; j++)
          cout << (it + 1) << " \n"[j == n / m - 1], it = (it + 1) % n;
      }
      int g = it;
      for (int i = 0; i < n % m; i++) {
        cout << n / m + 1 << ' ';
        for (int j = 0; j < n / m + 1; j++)
          cout << (g + 1) << " \n"[j == n / m], g = (g + 1) % n;
      }
    }
    cout << '\n';
  }
}

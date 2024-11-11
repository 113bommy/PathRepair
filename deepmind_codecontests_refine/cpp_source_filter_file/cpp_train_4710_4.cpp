#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:2000000")
using namespace std;
using ll = long long;
using db = long double;
using ii = pair<int, int>;
const int N = 2e5 + 5, LG = 19, MOD = 1e9 + 7;
const int SQ = 320;
const long double EPS = 1e-7;
vector<int> adj[100005];
int cnt = 0;
bitset<1024> bt;
int ans = 0;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    for (ll i = 0;; i++) {
      if (n > 3 * (1ll << (i + i))) {
        n -= (1ll << (i + i)) * 3;
      } else {
        if (n % 3 == 1) {
          n = 1 + n / 3;
          cout << (1ll << (i + i)) + n - 1 << '\n';
        } else if (n % 3 == 2) {
          n = 1 + n / 3;
          ll offset = (1ll << (i + i + 1));
          int ord[] = {0, 2, 3, 1};
          n--;
          int bits = i + i;
          for (int j = 0; j < bits; j += 2) {
            offset += ord[n % 4] << j;
            n >>= 2;
          }
          cout << offset << '\n';
        } else if (n % 3 == 0) {
          n /= 3;
          ll offset = 3 * (1ll << (i + i));
          n--;
          int ord[] = {0, 3, 1, 2};
          int bits = i + i;
          for (int j = 0; j < bits; j += 2) {
            offset += ord[n % 4] << j;
            n >>= 2;
          }
          cout << offset << '\n';
        }
        break;
      }
    }
  }
  return 0;
}

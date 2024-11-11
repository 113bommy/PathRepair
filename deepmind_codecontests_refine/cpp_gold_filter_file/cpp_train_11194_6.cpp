#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using ull = unsigned long long;
const long long INF = (1ll << 32);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if ((n + 1) / 2 > (a * b + 1) / 2) {
    cout << -1 << endl;
    return 0;
  }
  int p = 1, q = 2;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if ((i + j) % 2 == 0) {
        cout << (p > n ? 0 : p) << " "
             << "";
        p += 2;
      } else {
        cout << (q > n ? 0 : q) << " "
             << "";
        q += 2;
      }
    }
    cout << endl;
  }
  return 0;
}

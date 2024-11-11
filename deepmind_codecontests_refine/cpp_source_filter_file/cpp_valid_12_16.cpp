#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    int k1 = k, k2 = n * m / 2 - k1;
    bool flipped = false;
    if (m % 2) {
      flipped = true;
      swap(n, m);
      swap(k1, k2);
    }
    if (m % 2 == 0) {
      cout << (k2 % 2 == 0 ? "YES" : "NO") << '\n';
    } else {
      int r = m / 2;
      bool ok = r <= k1 && r % 2 == k1 % 2 && k2 % 2 == 0;
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }
}

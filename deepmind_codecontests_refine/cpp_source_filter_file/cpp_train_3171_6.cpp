#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const long long Linfi = (long long)9e18;
const long long MOD = 1000000007;
const int c1 = 31;
int n, m, L, R, x, y;
int bit[200005 + 5];
void update(int x, int val) {
  while (x < 200005) {
    bit[x] += val;
    x += (x & (-x));
  }
}
int get(int x) {
  int ans = 0;
  while (x > 0) {
    ans += bit[x];
    x -= (x & (-x));
  }
  return ans;
}
int get_unit(int x) { return get(x) - get(x - 1); }
void solve() {}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) update(i, 1);
  L = 1;
  R = n;
  int cmd, p;
  while (m--) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> p;
      if (L < R && 2 * p <= R - L + 1) {
        for (int i = 0; i <= p - 1; i++) {
          int tmp = get_unit(L + i);
          update(L + i, -tmp);
          update(2 * (L + p) - 1 - (L + i), tmp);
        }
        L = L + p;
      } else if (L < R && 2 * p > R - L + 1) {
        for (int i = 0; i <= R - L + 1 - p - 1; i++) {
          int tmp = get_unit(R - i);
          update(R - i, -tmp);
          update(2 * (L + p) - 1 - (R - i), tmp);
        }
        R = L;
        L = L + p - 1;
      } else if (L > R && 2 * p <= R - L + 1) {
        for (int i = 0; i <= p - 1; i++) {
          int tmp = get_unit(L - i);
          update(L - i, -tmp);
          update(2 * (L - p) + 1 - (L - i), tmp);
        }
        L = L - p;
      } else {
        for (int i = 0; i <= L - R + 1 - p - 1; i++) {
          int tmp = get_unit(R + i);
          update(R + i, -tmp);
          update(2 * (L - p) + 1 - (R + i), tmp);
        }
        R = L;
        L = L - p + 1;
      }
    } else if (cmd == 2) {
      cin >> x >> y;
      if (L <= R) {
        int ans = get(L + y - 1) - get(L + x - 1);
        cout << ans << endl;
      } else {
        int ans = get(L - x) - get(L - y);
        cout << ans << endl;
      }
    }
  }
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 1e6;
const long long LINF = (long long)1e18 + 1e9;
const double EPS = (double)1e-10;
const long long MOD = (long long)1e9 + 7;
long long power(long long x, long long y, long long mod = MOD) {
  if (y == 0) {
    return 1;
  }
  if (y & 1) {
    return power(x, y - 1, mod) * x % mod;
  } else {
    long long tmp = power(x, y / 2, mod);
    return tmp * tmp % mod;
  }
}
template <typename A, typename B>
bool mini(A &x, const B &y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}
template <typename A, typename B>
bool maxi(A &x, const B &y) {
  if (y > x) {
    x = y;
    return true;
  }
  return false;
}
void run();
int main() {
  if (strlen("")) {
    freopen(
        ""
        ".in",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  run();
  return 0;
}
const int N = (int)1e5 + 123;
int n;
int a[N];
bool ok[N];
int p[N];
void run() {
  cin >> n;
  ++n;
  for (auto i = 0; i < n; ++(i)) {
    cin >> a[i];
    ok[i] = (a[i] >= 2);
  }
  bool one = 1;
  int pos = -1;
  for (auto i = 0; i < n - 1; ++(i)) {
    if (ok[i] && ok[i + 1]) {
      one = 0;
      pos = i + 1;
    }
  }
  if (one) {
    cout << "perfect\n";
    return;
  } else {
    cout << "ambiguous\n";
    a[pos - 1]--;
    a[pos]--;
    for (auto i = 1; i < n + 1; ++(i)) {
      p[i] = i - 1;
    }
    int cur = n + 1;
    for (auto i = 0; i < n; ++(i)) {
      for (auto j = 0; j < a[i] - 1; ++(j)) {
        p[cur++] = i;
      }
    }
    for (auto i = 1; i < cur; ++(i)) {
      cout << p[i] << " ";
    }
    cout << pos - 1 << " " << cur << "\n";
    for (auto i = 1; i < cur; ++(i)) {
      cout << p[i] << " ";
    }
    cout << pos - 1 << " " << pos << "\n";
  }
}

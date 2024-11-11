#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<pair<int, int>>> vvpi;
typedef vector<vector<pair<long long, long long>>> vvpl;
long long power(int, long long, int);
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
template <class T>
int cov(vector<T>);
template <class T>
int covv(vector<vector<T>>);
template <class T>
bool umin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int a = n / k;
  if (a >= m) {
    cout << m << '\n';
    return;
  }
  cout << a - ((m - a - 1) % (k - 1) + 1) << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
template <class T>
int cov(vector<T> v) {
  int j = 0;
  while (v.begin() + j < v.end()) {
    cout << v[j] << ' ';
    j++;
  }
  cout << '\n';
  return 0;
}
template <class T>
int covv(vector<vector<T>> v) {
  int j = 0;
  while (v.begin() + j < v.end()) {
    cov(v[j]);
    j++;
  }
  return 0;
}
long long _inverse_power(int x, long long y, int w) {
  if (gcd(x, w) != 1) return -1;
  int z = w;
  int phi = z;
  for (int i = 2; i * i <= z; i++) {
    if (z % i) continue;
    while (z % i == 0) z /= i;
    phi /= i;
    phi *= i - 1;
  }
  phi /= z;
  phi *= z - 1;
  y %= phi;
  if (y < 0) y += phi;
  return power(x, y, w);
}
long long power(int x, long long y, int z) {
  if (y < 0) return _inverse_power(x, y, z);
  long long ret = 1;
  while (y) {
    if (y % 2 == 1) {
      ret *= x;
      ret %= z;
    }
    y >>= 1;
    x *= x;
    x %= z;
  }
  return ret;
}

#include <bits/stdc++.h>
using namespace std;
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (y == 0) return 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int modinv(long long int a, long long int p) {
  return power(a, p - 2, p);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      ans = max(ans, a[i] | a[j]);
    }
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      for (long long int k = j + 1; k < n; k++) {
        ans = max(ans, a[i] | a[j] | a[k]);
      }
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T = 1;
  for (long long int c = 0; c < T; c++) {
    solve();
  }
  return 0;
}

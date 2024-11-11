#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T u, T v) {
  while (v != 0) {
    T r = u % v;
    u = v;
    v = r;
  }
  return u;
}
template <typename T>
T factorial(T n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
int n;
double a[1005];
bool check(double m) {
  set<double> s;
  for (long long i = 1; i <= n; ++i) s.insert(a[i] - 1.0 * m * i);
  if (s.size() == 2) return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (check(a[2] - a[1]) || check(a[3] - a[1]) || check((a[3] - a[2]) / 2))
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}

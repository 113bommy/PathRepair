#include <bits/stdc++.h>
using namespace std;
template <typename T>
T __lcm(T a, T b);
int BigMod(int b, int p, int m);
template <typename T>
void SV(vector<T>& v);
int f(long long n) {
  if (n < 5) return max(1ll, n - 1);
  if ((n % 2 == 1) || (n % 4 == 0)) return (n - f(n - 1));
  return (n - f(n / 2));
}
void solve() {
  long long n;
  cin >> n;
  ;
  cout << f(n) << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
template <typename T>
T __lcm(T a, T b) {
  return (a * b) / __gcd(a, b);
}
int BigMod(int b, int p, int m) {
  if (p == 0) return 1 % m;
  int x = BigMod(b, p / 2, m);
  x = (x * x) % m;
  if (b % 2 == 1) x = (x * b) % m;
  return x;
}
template <typename T>
void SV(vector<T>& v) {
  for (auto itr = v.begin(); itr != v.end(); itr++) {
    cout << *itr << " ";
  }
  cout << endl;
}

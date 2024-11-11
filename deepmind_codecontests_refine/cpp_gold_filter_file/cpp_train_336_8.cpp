#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e6, MOD = 1e9 + 7;
ifstream infile;
ofstream outfile;
template <class T>
void inline Scan(vector<T> &arr) {
  for (auto &i : arr) cin >> i;
}
template <class T>
void inline Print(vector<T> &arr, char c) {
  for (auto &i : arr) cout << fixed << setprecision(7) << i << c;
}
template <class T>
istream &operator>>(istream &in, pair<T, T> &p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, pair<T, T> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
template <class T>
void swap(pair<T, T> &p) {
  swap(p.first, p.second);
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, int y) {
  long long ans = 1;
  while (y) {
    if (y % 2 == 1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    y = y / 2;
  }
  return ans;
}
template <class T>
T solve() {
  long long n, ans = 1;
  cin >> n;
  for (auto i = 2; i != n + 1; i++) ans = (ans * i) % MOD;
  ans = (ans - power(2, n - 1) + MOD) % MOD;
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  vector<int> ans(T);
  for (auto t = 0; t != T; t++) {
    solve<void>();
  }
  return 0;
}

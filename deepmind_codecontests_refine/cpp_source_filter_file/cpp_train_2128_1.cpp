#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &arr);
template <typename T>
ostream &operator<<(ostream &os, vector<T> &arr);
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p);
bool valid(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int INF = 1e9 + 7;
long long MOD = 998244353;
long long mul(long long a, long long b) { return (a % MOD * b % MOD) % MOD; }
long long add(long long a, long long b) { return (a % MOD + b % MOD) % MOD; }
long long doSomething(long long p, long long q, long long f) {
  if (f == 1) return 1;
  while (p % q == 0) p /= f;
  return p;
}
int main() {
  (ios_base::sync_with_stdio(false), cin.tie(0));
  int n, k;
  cin >> n >> k;
  if (n == 1 && k == 1)
    cout << -1;
  else if (n == 1 && k == 0)
    cout << 1;
  else if (k < n / 2) {
    cout << -1;
  } else {
    long long who = 3 * k + 1;
    for (int i = 0; i < n - 2 - n % 2; i += 2) {
      cout << who << " " << who + 1 << " ";
      who += 2;
      k--;
    }
    if (k > 0) cout << k << " " << 2 * k << " ";
    if (n % 2) cout << 2 * k + 1;
  }
  cout << endl;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    is >> *a;
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &arr) {
  typename vector<T>::iterator a;
  for (a = arr.begin(); a != arr.end(); a++) {
    os << *a << " ";
  }
  os << endl;
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
  os << p.first << " " << p.second << '\n';
  return os;
}

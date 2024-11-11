#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
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
  os << p.first << " " << p.second << " ";
  return os;
}
long long mul(long long a, long long b, long long md = MOD) {
  return (a % md * b % md) % md;
}
long long add(long long a, long long b, long long md = MOD) {
  long long ans = a + b;
  if (ans >= md) ans -= md;
  return ans;
}
bool valid(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
long long binPow(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y % 2 == 1) ans = mul(ans, x);
    x = mul(x, x);
    y /= 2;
  }
  return ans;
}
long long modInverse(long long x) { return binPow(x, MOD - 2); }
bool Good(long long x, int a, int b) {
  while (x) {
    if (x % 10 != a && x % 10 != b) {
      return false;
    }
    x /= 10;
  }
  return true;
}
int distance(pair<int, int> a, pair<int, int> b) {
  int dx = a.first - b.first;
  int dy = a.second - b.second;
  return dx * dx + dy * dy;
}
int main() {
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < int(n); i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  long long ans = 0;
  for (auto kv : cnt) {
    if (kv.first == 0)
      ans += (1ll * kv.second * (kv.second - 1)) / 2;
    else {
      if (cnt.count(-1 * kv.first)) ans += kv.second * cnt[-1 * kv.first];
      cnt[-1 * kv.first] = 0;
    }
  }
  cout << ans << endl;
}

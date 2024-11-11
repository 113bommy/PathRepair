#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;
template <typename T1, typename T2>
ostream& operator<<(ostream& ostream, pair<T1, T2>& p) {
  ostream << p.first << " " << p.second;
  return ostream;
}
template <typename T>
ostream& operator<<(ostream& stream, vector<T>& v) {
  for (const auto& it : v) stream << it << " ";
  return stream;
}
template <typename T1, typename T2>
istream& operator>>(istream& istream, pair<T1, T2>& p) {
  istream >> p.first >> p.second;
  return istream;
}
template <typename T>
istream& operator>>(istream& istream, vector<T>& a) {
  for (auto& it : a) istream >> it;
  return istream;
}
long long GCD(long long a, long long b) {
  if (!b) return a;
  return GCD(b, a % b);
}
long long LCM(long long a, long long b) { return (a * b) / GCD(a, b); }
long long modpow(long long x, long long n, long long m = 1000000007) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
void solve(long long tc) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ls = 0, rs = 0;
  long long l = 0, r = 0;
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] == '?') {
      l++;
      continue;
    }
    ls += s[i] - '0';
  }
  for (long long i = n / 2; i < n; i++) {
    if (s[i] == '?') {
      r++;
      continue;
    }
    rs += s[i] - '0';
  }
  if (ls == rs) {
    if (l != r)
      cout << "Monocarp";
    else
      cout << "Bicarp";
    return;
  }
  if (ls < rs) {
    swap(ls, rs);
    swap(l, r);
  }
  long long delta = ls - rs;
  if (l >= r)
    cout << "Monocarp";
  else {
    if (((r - l) / 2) * 9 >= delta)
      cout << "Bicarp";
    else
      cout << "Monocarp";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}

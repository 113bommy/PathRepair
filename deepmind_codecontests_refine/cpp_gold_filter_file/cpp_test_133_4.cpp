#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << "\b\b )" << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
template <class T>
using vc = vector<T>;
template <typename T1, typename T2>
pair<T1, T2>& operator+=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first += p2.first, p1.second += p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2>& operator-=(pair<T1, T2>& p1, const pair<T1, T2>& p2) {
  p1.first -= p2.first, p1.second -= p2.second;
  return p1;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 += p2;
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> p1, const pair<T1, T2>& p2) {
  return p1 -= p2;
}
template <typename T>
T operator*(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.first + p1.second * p2.second;
}
template <typename T>
T operator^(const pair<T, T>& p1, const pair<T, T>& p2) {
  return p1.first * p2.second - p2.first * p1.second;
}
template <typename T>
pair<T, T>& operator*=(pair<T, T>& p1, const T& p2) {
  p1.first *= p2;
  p1.second *= p2;
  return p1;
}
template <typename T>
pair<T, T> operator*(pair<T, T> p1, const T& p2) {
  return p1 *= p2;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << p.first << ' ' << p.second;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<T>& a) {
  for (auto& v : a) os << (v) << ' ';
  return os;
}
template <typename T>
istream& operator>>(istream& is, vc<T>& a) {
  for (auto& v : a) is >> v;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vc<vc<T>>& a) {
  for (auto& v : a) os << v << '\n';
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& a) {
  for (auto& v : a)
    os << '\n' << setw(15) << v.first << " : " << v.second << ' ';
  return os;
}
template <typename T>
vc<T>& operator+=(vc<T>& a, const vc<T>& b) {
  for (auto& v : b) a.emplace_back(v);
  return a;
}
template <typename T>
vc<T> operator+(vc<T> a, const vc<T>& b) {
  return a += b;
}
template <typename T>
vc<T>& operator+=(vc<T>& a, const T& b) {
  for (auto& v : a) v += b;
  return a;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lca(long long a, long long b) { return a * b / gcd(a, b); }
const int P = 13331;
const double eps = 1e-10;
const int N = 2e5 + 10, M = 2 * N, MOD = 1e9 + 7, INF = 0x3f3f3f3f;
int n, m;
void solve(int caseT) {
  cin >> n;
  if (n == 3) {
    string s;
    cin >> s;
    cout << s << 'a' << '\n';
    return;
  }
  char last = ' ';
  m = 0;
  for (int i = 1; i <= n - 2; i++) {
    string s;
    cin >> s;
    if (i == 1 || last == s[0])
      cout << s[0], m++;
    else {
      cout << last << s[0];
      m += 2;
    }
    if (i == n - 2) {
      if (m == n - 1)
        cout << s[1], m += 1;
      else if (m <= n - 2)
        cout << s, m += 2;
    }
    last = s[1];
  }
  if (m < n) cout << 'a';
  cout << '\n';
}
void init() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int T;
  T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) solve(i);
  return 0;
}

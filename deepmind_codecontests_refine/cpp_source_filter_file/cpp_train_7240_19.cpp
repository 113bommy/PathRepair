#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ll;
typedef vector<long long> vl;
typedef vector<ll> vll;
typedef vector<vl> vvl;
template <typename T>
ostream &operator<<(ostream &o, vector<T> v) {
  if (v.size() > 0) o << v[0];
  for (unsigned i = 1; i < v.size(); i++) o << " " << v[i];
  return o << "\n";
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (unsigned i = 0; i < v.size(); i++) in >> v[i];
  return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p) {
  in >> p.first;
  in >> p.second;
  return in;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  long long n;
  cin >> n;
  vl a(n);
  cin >> a;
  for (long long i = (0); i < (long long)n - 1; i++) a[i] += a[i - 1];
  cout << a;
  return 0;
}

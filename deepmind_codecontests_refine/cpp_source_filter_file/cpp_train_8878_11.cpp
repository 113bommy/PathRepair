#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
const long long MAXN = 1e5 + 7;
long long get(long long x) {
  long long ret = 0, i = 1, pw = 1, y = x;
  while (x) {
    long long l = x % 10;
    if (l == 4 || l == 7) ret = ret + (l * pw), pw *= 10;
    x /= 10;
  }
  return ret;
}
void check() {
  long long n, b;
  cin >> n >> b;
  while (get(n) != b) n++;
  cout << n;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    check();
  }
  return 0;
}

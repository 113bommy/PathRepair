#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& prnt(ostream& out, T v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  return prnt(out, v);
}
template <class T>
ostream& operator<<(ostream& out, set<T> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ' ' << p.second << ')';
}
const int N = 1e5 + 100;
int n, k, m, x[N], a[N], f[2][N * 10];
long long ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) x[i] = x[i - 1] ^ a[i];
  f[0][0]++;
  for (int i = 1; i <= n; i++) {
    ans += f[i % 2][x[i]];
    f[i % 2][x[i]]++;
  }
  cout << ans << '\n';
}

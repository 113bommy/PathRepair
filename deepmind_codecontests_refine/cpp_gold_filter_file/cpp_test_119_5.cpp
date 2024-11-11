#include <bits/stdc++.h>
using namespace std;
template <class T>
istream &operator>>(istream &in, vector<T> &a) {
  for (auto &i : a) in >> i;
  return in;
}
template <class T>
ostream &operator<<(ostream &out, vector<T> &a) {
  for (auto &i : a) out << i << ' ';
  return out;
}
template <class T, class U>
istream &operator>>(istream &in, pair<T, U> &a) {
  in >> a.first >> a.second;
  return in;
}
template <class T, class U>
ostream &operator<<(ostream &out, pair<T, U> &a) {
  out << a.first << ' ' << a.second << "\n";
  return out;
}
mt19937 rnd(time(NULL));
void files() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return (a < b ? a : b);
}
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return (a > b ? a : b);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  long long second = accumulate((a).begin(), (a).end(), (long long)0);
  if (second % n)
    cout << 1 << "\n";
  else
    cout << 0 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  cin >> q;
  while (q--) {
    solve();
  }
}

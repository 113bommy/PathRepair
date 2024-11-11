#include <bits/stdc++.h>
using namespace std;
long long dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
long long dy[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
  os << '{';
  string sep;
  for (const auto &x : arr) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
vector<long long> st[200005], en[200005];
void solve(long long tt) {
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  long long ansji = 1e18;
  for (long long i = 0; i < (long long)m; i++) {
    long long a;
    cin >> a;
    long long b;
    cin >> b;
    ansji = min(ansji, b - a + 1);
  }
  cout << ansji << "\n";
  for (long long i = 0; i < (long long)n; i++) {
    cout << i % ansji << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long nn = 1;
  for (long long i = 0; i < (long long)nn; i++) solve(i + 1);
}

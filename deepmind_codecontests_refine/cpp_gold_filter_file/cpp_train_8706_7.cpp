#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long max(long long a, long long b) { return (a > b ? a : b); }
long long min(long long a, long long b) { return (a > b ? b : a); }
void printa(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  cout << "\n";
}
void printv(vector<long long> v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << "\n";
}
void printset(set<long long> s) {
  for (auto x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
void printmset(multiset<long long> s) {
  for (auto x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
void printmgset(multiset<long long, greater<long long>> s) {
  for (auto x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
const long long inf = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
long long fact(long long n) { return (n == 1 || n == 0) ? 1 : n * fact(n - 1); }
const long long N = 1e6 + 1;
void solve() {
  vector<long long> v(3);
  for (long long i = 0; i < (3); ++i) {
    cin >> v[i];
  }
  sort((v).begin(), (v).end());
  long long c = 0;
  if (v[0] == 2 && v[1] == 4 && v[2] == 4) {
    c = 1;
  }
  if (v[0] == 1 || v[1] == 1 || v[2] == 1) {
    c = 1;
  }
  if (v[0] == 3 && v[1] == 3 && v[2] == 3) {
    c = 1;
  }
  if ((v[0] == 2 && v[1] == 2) || (v[1] == 2 && v[2] == 2) ||
      (v[2] == 2 && v[0] == 2)) {
    c = 1;
  }
  cout << (c ? "YES" : "NO") << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}

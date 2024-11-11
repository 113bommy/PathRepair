#include <bits/stdc++.h>
const long long mod = 1000000000 + 7;
const long long INF = 9000000000000000000;
using namespace std;
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
long long gcd(long long a, long long b) { return (a == 0 ? b : gcd(b % a, a)); }
long long lcm(long long a, long long b) { return (a * b / (gcd(a, b))); }
long long add(long long a, long long b, long long c = 0) {
  return ((a % mod + b % mod) % mod + c % mod) % mod;
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long sub(long long a, long long b) {
  return (a % mod - b % mod + mod) % mod;
}
void print(vector<long long> ans) {
  for (auto x : ans) cout << x << " ";
  cout << endl;
}
long long n, a, w, k, b, h, x, y, m, mx, cc, timer, realans, start, queries,
    startindex;
string s, t;
long long arr[100005];
void solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  cin >> s;
  long long curr = 0;
  for (long long i = 0; i < n; i++)
    if (s[i] == '1') curr += arr[i];
  long long mx = curr, zero_sum = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1')
      mx = max(mx, curr - arr[i] + zero_sum);
    else
      zero_sum += arr[i];
  }
  cout << mx << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tests = 1;
  while (tests--) {
    solve();
  }
  return 0;
}

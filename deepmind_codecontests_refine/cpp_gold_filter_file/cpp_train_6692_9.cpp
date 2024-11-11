#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
void out(vector<long long> arr) {
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << "\n";
}
void out(vector<pair<long long, long long>> par) {
  for (auto i : par) {
    cout << i.first << ' ';
  }
  cout << endl;
  for (auto i : par) {
    cout << i.second << ' ';
  }
  cout << endl;
}
void out(set<long long> arr) {
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}
void inp(vector<long long> &arr) {
  for (long long i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
}
void inp(long long &n) { cin >> n; }
void inp(long long &a, long long &b, long long &c) { cin >> a >> b >> c; }
void inp(long long &a, long long &b) { cin >> a >> b; }
void inp(long long &a, long long &b, long long &c, long long &d) {
  cin >> a >> b >> c >> d;
}
long long MOD = 1e9 + 7;
const long long N = 2e5 + 10;
;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    long long x = n[0] - '0';
    long long ans = (x - 1) * 10;
    for (long long i = 0; i < n.size(); i++) {
      ans += i + 1;
    }
    cout << ans << "\n";
  }
}

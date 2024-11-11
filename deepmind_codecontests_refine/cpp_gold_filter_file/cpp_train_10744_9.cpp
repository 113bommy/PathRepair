#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
const long long mod = 1e9 + 7;
bool is(long long n) { return (ceil(log2(n)) == floor(log2(n))); }
bool q(const pair<long long, long long> &a,
       const pair<long long, long long> &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
bool q2(const pair<long long, long long> &a,
        const pair<long long, long long> &b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first > b.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1, r, g, b;
  cin >> t;
  while (t--) {
    cin >> r >> g >> b;
    long long mx = max(r, max(g, b));
    long long mn = min(r, min(g, b));
    long long mid = r + g + b - mx - mn;
    if (mn + mid >= mx - 1) {
      cout << "Yes\n";
    } else
      cout << "No\n";
  }
  return 0;
}

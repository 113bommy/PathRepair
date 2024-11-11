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
  long long t = 1;
  long long n, x, y, ans;
  while (t--) {
    cin >> n >> x >> y;
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (ans = 1; ans <= n; ans++) {
      bool first = true;
      for (int i = ans - 1; i >= max(ans - x, 1LL); i--)
        if (a[i] < a[ans]) {
          first = false;
          break;
        }
      for (int i = ans + 1; i <= min(ans + y, n); i++)
        if (a[i] < a[ans]) {
          first = false;
          break;
        }
      if (first) break;
    }
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long double pi = acos(-1.0);
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
long long binpows(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int binpow(int a, int b, int m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(((i + a) % n + n) % n);
  }
  if (s.size() == n) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
signed main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

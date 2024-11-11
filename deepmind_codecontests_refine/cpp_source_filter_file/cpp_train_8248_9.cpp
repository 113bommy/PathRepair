#include <bits/stdc++.h>
long long p = 1e15 + 7;
const long long infll = 1e18;
unsigned long long power(unsigned long long x, long long y) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
using namespace std;
const int N = 1025;
int n;
int a[N];
bool is[N];
bool check(int k) {
  for (int i = 1; i <= n; i++) {
    if (is[a[i] ^ k] == false) return false;
  }
  return true;
}
void solve() {
  cin >> n;
  for (int i = 0; i < N; i++) {
    is[i] = false;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    is[a[i]] = true;
  }
  for (int i = 1; i < 1025; i++) {
    if (check(i)) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
}

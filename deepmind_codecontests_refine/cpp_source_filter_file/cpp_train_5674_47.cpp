#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int powmod(long long a, int b) {
  long long res = 1;
  if (a >= mod) a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= mod) res %= mod;
    a = a * a;
    if (a >= mod) a %= mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int a[105] = {0}, b[105] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  ;
  int i, j, t;
  int n, m;
  cin >> n >> m;
  int val, idx;
  idx = 1;
  int cur;
  val = -1;
  for (i = 1; i <= n; i++) {
    cur = -1;
    for (j = 1; j <= m; j++) {
      cin >> val;
      if (val > cur) {
        cur = val;
        idx = j;
      }
    }
    a[i] = idx;
  }
  for (i = 1; i <= 100; i++) b[a[i]]++;
  val = -1;
  for (i = 1; i <= 100; i++) {
    if (val < b[i]) {
      val = b[i];
      idx = i;
    }
  }
  cout << idx << '\n';
  return 0;
}

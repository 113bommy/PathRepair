#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 150;
const int INF = 1 << 28;
const double EPS = 1e-9;
const double PI = 3.14159265358979;
const int MOD = 1000000000;
int n, m;
int a[MAX_N];
int fib[MAX_N];
void init() {
  fib[0] = fib[1] = 1;
  for (int i = (2); i < (MAX_N); i++) {
    fib[i] = ((long long)fib[i - 1] + fib[i - 2]) % MOD;
  }
}
void solve() {
  for (int i = (0); i < (m); i++) {
    int t, x, v, l, r, s;
    cin >> t;
    switch (t) {
      case 1:
        cin >> x >> v;
        x--;
        a[x] = v;
        break;
      case 2:
        cin >> l >> r;
        l--;
        s = 0;
        for (int i = (l); i < (r); i++) {
          s = ((long long)s + (long long)fib[i - l] * a[i]) % MOD;
        }
        cout << s << endl;
        break;
      case 3:
        break;
    }
  }
}
int main() {
  init();
  cin >> n >> m;
  for (int i = (0); i < (n); i++) cin >> a[i];
  solve();
  return 0;
}

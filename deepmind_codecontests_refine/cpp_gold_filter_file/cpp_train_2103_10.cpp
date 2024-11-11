#include <bits/stdc++.h>
using namespace std;
const int nmax = 2E5 + 5;
const int INF = 1E9;
const long long INFll = 1E16;
int t = 1;
void INPUT() { cin >> t; }
void INIT() {}
int a, b, c, d, k;
void SOLVE() {
  cin >> a >> b >> c >> d >> k;
  int ans = -1;
  for (int i = 1; i < k; i++) {
    if (i * c >= a && (k - i) * d >= b) {
      cout << i << " " << k - i << endl;
      return;
    }
  }
  cout << -1 << endl;
}
int main() {
  if (fopen("test"
            ".inp",
            "r")) {
    freopen(
        "test"
        ".inp",
        "r", stdin);
    freopen(
        "test"
        ".out",
        "w", stdout);
  }
  INPUT();
  INIT();
  while (t--) SOLVE();
}

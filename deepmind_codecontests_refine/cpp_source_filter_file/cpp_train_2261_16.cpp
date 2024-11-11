#include <bits/stdc++.h>
using namespace std;
const long double pi = 2 * acos(0);
const long double eps = 1e-6;
const int MAX = 200;
int n, a[MAX], ans;
void unit() {
  cin >> n;
  for (int i = 1; i <= n + n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n + n; i += 2) {
    int cutie = -1;
    for (int j = i + 1; j <= n + n; ++j) {
      if (a[i] == a[j]) {
        cutie = j;
        break;
      }
    }
    ans += cutie - i - 1;
    for (int j = cutie; j > i; --j) {
      a[j] = a[j - 1];
    }
  }
  cout << ans << "\n";
}
void solve() { unit(); }
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}

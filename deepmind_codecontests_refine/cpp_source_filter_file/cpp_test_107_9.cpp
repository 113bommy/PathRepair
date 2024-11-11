#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1) {
    cout << "-1\n";
    return;
  }
  if (a > b) {
    if (2 * a + 1 > n) {
      cout << "-1\n";
      return;
    }
    cout << "1 ";
    for (long long i = a + 2; i <= n - a; i++) cout << i << " ";
    for (long long i = 2; i <= a + 1; i++) {
      cout << n - i + 2 << " " << i << " ";
    }
    cout << "\n";
  } else if (b > a) {
    if (2 * b + 1 > n) {
      cout << "-1\n";
      return;
    }
    cout << n << " ";
    for (long long i = n - b - 1; i > b; i--) {
      cout << i << " ";
    }
    for (long long i = 1; i <= b; i++) {
      cout << i << " " << n - i << " ";
    }
    cout << "\n";
  } else {
    if (2 * a + 1 > n) {
      cout << "-1\n";
      return;
    }
    if (n == 1) {
      cout << "1\n";
      return;
    }
    cout << "1 ";
    for (long long i = a + 2; i < n - a; i++) cout << i << " ";
    cout << n << " ";
    for (long long i = 2; i <= a + 1; i++) {
      cout << i << " " << n - i + 1 << " ";
    }
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) solve();
  return 0;
}

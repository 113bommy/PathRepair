#include <bits/stdc++.h>
using namespace std;
void TestCase() {
  unsigned long long n, m, k;
  cin >> n >> m >> k;
  unsigned long long mx = max(n, m);
  if (mx > k) {
    cout << "-1\n";
    return;
  } else if (n % 2 == m % 2) {
    if ((k - mx) % 2 == 1) {
      cout << mx + (k - mx - 2) << '\n';
    } else {
      cout << mx + (k - mx) << '\n';
    }
  } else {
    cout << mx + (k - mx - 1) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    TestCase();
  }
  return 0;
}

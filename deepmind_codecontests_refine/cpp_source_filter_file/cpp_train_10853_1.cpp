#include <bits/stdc++.h>
using namespace std;
string FIRST = "Ashishgup\n", SECOND = "FastestFinger\n";
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << SECOND;
    return;
  }
  if (n % 2 || n == 2) {
    cout << FIRST;
    return;
  }
  long long ch = 1, nech = 0;
  for (long long i = 2; i <= (long long)1e5; i++) {
    while (n % i == 0) {
      n /= i;
      if (i % 2 == 0)
        ch *= i;
      else
        nech++;
    }
  }
  if (n > 1) nech++;
  if (ch == 2 && nech >= 1) {
    cout << SECOND;
    return;
  }
  if (nech == 0) {
    cout << SECOND;
    return;
  }
  cout << FIRST;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}

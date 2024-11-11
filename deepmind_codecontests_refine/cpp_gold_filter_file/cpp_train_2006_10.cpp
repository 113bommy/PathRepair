#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, d;
  cin >> n >> d;
  if (d > n) {
    cout << d - n << "\n";
    return;
  }
  if (n % 2 == 0) {
    if (d % 2 == 0 && d <= n) {
      cout << "0"
           << "\n";
      return;
    } else {
      cout << "1"
           << "\n";
      return;
    }
  } else {
    if (d % 2 != 0 && d <= n) {
      cout << "0"
           << "\n";
      return;
    } else {
      cout << "1"
           << "\n";
      return;
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}

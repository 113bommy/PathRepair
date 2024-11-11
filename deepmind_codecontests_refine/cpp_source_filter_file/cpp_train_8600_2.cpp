#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n % 4 == 0)
    cout << n / 4 << "\n";
  else if (n % 4 == 1) {
    if (n / 4 >= 2)
      cout << n / 4 - 2 + 1 << "\n";
    else
      cout << -1 << "\n";
  } else if (n % 4 == 2) {
    if (n / 4 >= 1)
      cout << n / 4 - 1 + 1 << "\n";
    else
      cout << -1 << "\n";
  } else {
    if (n / 4 >= 3)
      cout << n / 4 + 2 - 1 << "\n";
    else
      cout << -1 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}

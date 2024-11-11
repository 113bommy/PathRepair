#include <bits/stdc++.h>
using namespace std;
void solveTestCase() {
  long long int n;
  cin >> n;
  if (n % 4) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    solveTestCase();
  }
  return 0;
}

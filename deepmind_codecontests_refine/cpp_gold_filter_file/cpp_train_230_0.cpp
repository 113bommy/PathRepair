#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265359;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << fixed << setprecision(10) << cos(pi / (4 * n)) / sin(pi / (n * 2))
         << '\n';
  }
  return 0;
}

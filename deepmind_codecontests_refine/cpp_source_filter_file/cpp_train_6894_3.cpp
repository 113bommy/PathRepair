#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
const int N = 2e5 + 5;
const double pi = acos(-1);
int t;
int main() {
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n == 2 * m)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}

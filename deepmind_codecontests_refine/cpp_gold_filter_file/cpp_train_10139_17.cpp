#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double DEG2RAD = 0.017453292;
const double RAD2DEG = 57.29578049;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    if (i < n % m)
      cout << n / m + 1;
    else
      cout << n / m;
    cout << " ";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 10005;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n, k, ma, mi;
int main() {
  cin >> n >> k;
  if (3 * k > n)
    ma = n - k;
  else
    ma = 2 * k;
  mi = 1;
  if (k == n || k == 0) mi = ma = 0;
  cout << mi << " " << ma << endl;
  return 0;
}

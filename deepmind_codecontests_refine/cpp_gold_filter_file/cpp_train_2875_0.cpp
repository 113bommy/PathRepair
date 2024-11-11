#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e10, INF = 1e6, MAXN = 4e5 + 4e2;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 0 << " " << 0;
    return 0;
  }
  if (n == k) {
    cout << 0 << " ";
  } else {
    cout << 1 << " ";
  }
  cout << min((n - k), (2 * k));
  return 0;
}

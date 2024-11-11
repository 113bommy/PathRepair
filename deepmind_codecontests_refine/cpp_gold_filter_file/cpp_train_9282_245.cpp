#include <bits/stdc++.h>
using namespace std;
const long long INF = 1ll << 32;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n <= m && n <= k) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

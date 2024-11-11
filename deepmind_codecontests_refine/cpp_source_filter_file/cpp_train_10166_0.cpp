#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 1;
const long long INF = 1e18 + 1;
int main() {
  ios_base::sync_with_stdio(0);
  long long p, y;
  cin >> p >> y;
  for (int i = y; i > p; --i) {
    bool tf = 1;
    for (int j = 2; j * j <= i; ++j) {
      if (i / j > p) {
      } else {
        if (i % j == 0 && i / j != 1) {
          tf = 0;
          break;
        }
      }
    }
    if (tf) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}

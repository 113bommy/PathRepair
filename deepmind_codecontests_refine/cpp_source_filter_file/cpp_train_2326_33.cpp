#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e3 + 10;
int main() {
  int d, n, x;
  long long ans = 0;
  cin >> d >> n;
  while (n--) {
    cin >> x;
    ans += d - x;
  }
  cout << ans << endl;
  return 0;
}

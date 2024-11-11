#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int inf = 2e9;
int main() {
  long long n, ans = 0, k = 1, d = 10;
  cin >> n;
  n--;
  if (n < 1e8) {
    for (int i = 1; i <= n; i++) {
      if (i >= d) {
        k++;
        d *= 10;
      }
      ans += k;
    }
    cout << ans;
    return 0;
  }
  if (n == 1e9) {
    cout << "8888888899";
    return 0;
  }
  n -= 1e8;
  n++;
  cout << n * 9 + 788888889;
  return 0;
}

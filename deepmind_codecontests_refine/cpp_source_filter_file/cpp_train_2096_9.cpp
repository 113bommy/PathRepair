#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long r = 1;
  while (b != 0) {
    if (b % 2 != 0) {
      r = r * a;
      r %= 998244353;
    }
    a = a * a;
    a = a % 998244353;
    b = b / 2;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  int ans[1009], j;
  memset(ans, -1, sizeof(ans));
  for (int i = 3; i <= 180; i++) {
    j = 1;
    while (1) {
      int k = (180) * j;
      int p = k / i;
      if ((k % i) == 0) {
        if (ans[p] == -1) {
          ans[p] = i;
        }
      }
      j = j + 1;
      if (j > (i - 2)) {
        break;
      }
    }
  }
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << endl;
  }
}

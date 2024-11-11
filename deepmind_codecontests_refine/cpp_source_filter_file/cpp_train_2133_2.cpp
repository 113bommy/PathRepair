#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000")
using namespace std;
const int N = 100005;
long long getk(int A, int B, int i) { return A + (long long)(i - 1) * B; }
int main() {
  int A, B, q;
  cin >> A >> B >> q;
  while (q--) {
    long long le, lim, m;
    cin >> le >> lim >> m;
    long long k = getk(A, B, le);
    long long maxi = 0, cota = 1e9;
    while (maxi + 1 < cota) {
      long long mid = (maxi + cota) / 2;
      if (2 * mid * k + B * mid * (mid - 1) <= 2 * lim * m) {
        maxi = mid;
      } else {
        cota = mid;
      }
    }
    maxi = min(maxi, (lim - k) / B + 1);
    cout << (maxi >= 1 ? (le + maxi - 1) : -1) << endl;
  }
  return 0;
}

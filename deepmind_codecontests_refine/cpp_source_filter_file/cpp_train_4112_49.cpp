#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long ty = n;
  long long ln = 0;
  while (ty > 0) {
    ty = ty / 10;
    ln++;
  }
  long long po = pow(10, ln - 1);
  long long ans = 0;
  ans += (n - po + 1) * ln;
  while (ln-- && ln > 0) {
    long long ml = pow(10, ln - 1);
    ans += 9 * ml;
  }
  cout << ans << "\n";
}

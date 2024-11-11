#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long N = 1000000;
const double pi = 3.1415926535897932384626433832795;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  srand(time(0));
  long long n, a, b, c, ans = 0;
  cin >> n;
  cin >> a >> b >> c;
  n--;
  long long now = 1;
  while (n) {
    n--;
    if (now == 1) {
      if (a < b)
        now = 2, ans += a;
      else
        now = 3, ans += b;
    } else if (now == 2) {
      if (a < c)
        ans += a, now = 1;
      else
        ans += c, now = 3;
    } else {
      if (b < c)
        ans += b, now = 1;
      else
        ans += c, now = 2;
    }
  }
  cout << ans << endl;
  return 0;
}

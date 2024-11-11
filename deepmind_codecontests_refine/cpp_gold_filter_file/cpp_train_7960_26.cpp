#include <bits/stdc++.h>
using namespace std;
const long double INF = 1e18 + 7;
long long N = 1e6 * 5;
long double EPS = 1 / 1e18;
long double PI = 3.14159265358979323846;
long long first[8] = {2, 3, 322, 5, 53, 7, 7222, 7332}, ans[70];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, cnt = 0;
  cin >> n;
  string second;
  cin >> second;
  for (long long i = 0; i < n; i++) {
    if (second[i] - '0' >= 2) {
      long long num = first[second[i] - '2'];
      for (; num > 0;) {
        ans[cnt++] = num % 10;
        num /= 10;
      }
    }
  }
  sort(ans, ans + cnt);
  for (long long i = cnt - 1; i >= 0; i--) cout << ans[i];
  return 0;
}

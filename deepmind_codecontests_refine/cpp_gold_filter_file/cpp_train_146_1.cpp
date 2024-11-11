#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9;
bool check(long long a, long long b) { return a < b; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  {
    long long n;
    cin >> n;
    long long k, a[n], x = 0, y = 0, e = 0, o = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == 200)
        e++;
      else
        o++;
    }
    if (n == 1 || (n % 2 != 0 && (e == 0 || o == 0)))
      cout << "NO";
    else if (e % 2 == 0 && o % 2 == 0) {
      cout << "YES";
    } else if (o % 2 == 0) {
      cout << "YES";
    } else
      cout << "NO";
  }
  return 0;
}

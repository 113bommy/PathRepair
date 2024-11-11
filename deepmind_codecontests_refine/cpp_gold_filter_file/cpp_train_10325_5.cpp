#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long sum = 0, maxx = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    sum += a;
    maxx = max(maxx, a);
  }
  if (sum % 2 == 1 || sum < maxx * 2)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}

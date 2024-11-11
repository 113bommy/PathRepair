#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long tm = 0;
  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    long long t, c;
    cin >> t >> c;
    if (tm < t) {
      tm = t + c;
    } else {
      tm += c;
    }
    ans = max(ans, tm - t);
  }
  cout << tm << " " << ans << endl;
  return 0;
}

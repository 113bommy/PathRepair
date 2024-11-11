#include <bits/stdc++.h>
using namespace std;
int main() {
  long long xsum, xxor;
  cin >> xsum >> xxor;
  long long a = (xsum - xxor) >> 1LL;
  long long b = xsum - a;
  if (xsum >= xxor && (a ^ b) == xxor) {
    long long ans = 1LL << __builtin_popcountll(xxor);
    if (xsum == xxor) {
      ans -= 2;
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}

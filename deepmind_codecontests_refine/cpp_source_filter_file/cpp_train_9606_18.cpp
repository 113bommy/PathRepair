#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, a;
    long long mp[40], ans = 0;
    memset(mp, 0, sizeof(mp));
    cin >> n;
    while (n--) {
      scanf("%I64d", &a);
      for (long long i = 35; i >= 0; i--)
        if ((1 << i) & a) {
          ans += mp[i];
          mp[i]++;
          break;
        }
    }
    cout << ans << endl;
  }
  return 0;
}

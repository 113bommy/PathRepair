#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int rc[n], cc[n];
  for (__typeof(n) i = (0); i != (n); i++) rc[i] = cc[i] = 0;
  for (__typeof(n) i = (0); i != (n); i++)
    for (__typeof(n) j = (0); j != (n); j++) {
      char c;
      cin >> c;
      if (c == 'C') {
        rc[i]++;
        cc[j]++;
      }
    }
  int ans = 0;
  for (__typeof(n) i = (0); i != (n); i++) {
    ans += (rc[i] * (rc[i] - 1)) / 2;
    ans += (cc[i] * (cc[i] - 1)) / 2;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    float n;
    cin >> n;
    long long int flag = 0;
    for (float i = 3; i < 300; i++) {
      float x = (i - 2) * (180 / i);
      if (x == n) {
        flag = 1;
      }
    }
    if (flag)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}

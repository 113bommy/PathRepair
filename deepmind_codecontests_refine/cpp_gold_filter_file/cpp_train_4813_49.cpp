#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int aans, bans, cans;
    long long int cost = 1e18;
    for (long long int i = 1; i <= 20000; i++) {
      for (long long int j = i; j <= 20000; j += i) {
        for (long long int k = j; k <= 20000; k += j) {
          long long int min1 = abs(a - i) + abs(j - b) + abs(k - c);
          if (cost > min1) {
            cost = min1;
            aans = i;
            bans = j;
            cans = k;
          }
        }
      }
    }
    cout << cost << endl;
    cout << aans << " " << bans << " " << cans << endl;
  }
}

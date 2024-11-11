#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
long long int t;
string second;
map<pair<long long int, long long int>, long long int> viz;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    long long int x = 0, y = 0;
    viz.clear();
    second = "";
    cin >> second;
    long long int ans = 0;
    for (long long int i = 0; i < second.size(); i++) {
      if (second[i] == 'N') {
        x = x + 2;
        if (viz[{x - 1, y}] == 1) {
          ans++;
        } else
          ans = ans + 5;
        viz[{x - 1, y}] = 1;
      } else if (second[i] == 'S') {
        x = x - 2;
        if (viz[{x + 1, y}] == 1) {
          ans++;
        } else
          ans = ans + 5;
        viz[{x + 1, y}] = 1;
      } else if (second[i] == 'E') {
        y = y - 2;
        if (viz[{x, y + 1}] == 1) {
          ans++;
        } else
          ans = ans + 5;
        viz[{x, y + 1}] = 1;
      } else if (second[i] == 'W') {
        y = y + 2;
        if (viz[{x, y - 1}] == 1) {
          ans++;
        } else
          ans = ans + 5;
        viz[{x, y - 1}] = 1;
      }
    }
    cout << ans << '\n';
  }
}

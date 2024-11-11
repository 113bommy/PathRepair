#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    unsigned long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    unordered_map<unsigned long long int, unsigned long long int> mp, mp1;
    for (int i = 1; i <= 100000; i++) {
      ++mp[b + (i * a)];
      ++mp1[d + (i * c)];
    }
    for (int i = 1; i <= 100000; i++) {
      if (mp[i] && mp1[i]) {
        cout << i;
        return 0;
      }
    }
    cout << -1;
  }
}

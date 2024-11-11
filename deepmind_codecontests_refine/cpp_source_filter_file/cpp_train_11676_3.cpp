#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> m;
    int ans = 0;
    while (n && m[n] == 0) {
      m[n]++;
      n++;
      ans++;
      while (n % 10 == 0) n /= 10;
    }
    cout << ans << endl;
  }
}

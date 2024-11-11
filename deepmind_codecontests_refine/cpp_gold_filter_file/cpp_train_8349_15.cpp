#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, m;
    cin >> h >> m;
    int ans = 0;
    ans += 60 - m;
    h++;
    ans += (24 - h) * 60;
    cout << ans << "\n";
  }
}

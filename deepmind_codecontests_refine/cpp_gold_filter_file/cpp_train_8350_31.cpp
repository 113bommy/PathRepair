#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, ans = 0;
    cin >> n >> m;
    int x = 23 - n;
    ans += x * 60;
    ans += 60 - m;
    cout << ans << '\n';
  }
}

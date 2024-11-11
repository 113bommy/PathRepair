#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int ans = 2400 - (a * 60 + b);
    cout << ans << endl;
  }
  return 0;
}

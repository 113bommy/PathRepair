#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    unsigned long long ans;
    ans = (a + b + c) / 2;
    cout << ans << endl;
  }
  return 0;
}

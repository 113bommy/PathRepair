#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    long long w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    long long ans = 0;
    ans = 2 * (h1 + h2 + w1 + 2);
    cout << ans << endl;
  }
  return 0;
}

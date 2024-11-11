#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int ans1 = (k * l) / n;
  int ans2 = c * d;
  int ans3 = p / np;
  int ans = ((ans1 > ans2) ? ans2 < ans3 ? ans2 : ans3
             : ans1 < ans3 ? ans1
                           : ans3) /
            n;
  cout << ans << endl;
  return 0;
}

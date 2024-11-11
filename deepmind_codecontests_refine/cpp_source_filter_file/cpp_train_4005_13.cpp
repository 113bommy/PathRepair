#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long mask = 0;
    for (int i = 0; i < 32; ++i) {
      if ((l | (1LL << mask)) <= r) {
        l |= (1LL << mask);
        ++mask;
      } else
        break;
    }
    cout << l << "\n";
  }
  return 0;
}

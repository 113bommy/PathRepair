#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      ans ^= v[i];
    }
    if (ans == 0) {
      cout << "DRAW\n";
      continue;
    }
    long long msb = 1 << (long long)log2(ans);
    ans = 0;
    bool ans2 = 0;
    for (int i = 0; i < n; i++) {
      if (msb & v[i])
        ans++;
      else
        ans2 = !ans2;
    }
    if (ans % 4 == 3 && ans2) {
      cout << "LOSE\n";
    } else {
      cout << "WIN\n";
    }
  }
}

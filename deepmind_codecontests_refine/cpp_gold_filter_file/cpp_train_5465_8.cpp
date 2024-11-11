#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, S, q;
  cin >> T >> S >> q;
  int ans = 0;
  while (S < T) {
    S *= q;
    ans++;
  }
  cout << ans;
  return 0;
}

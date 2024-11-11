#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  int i;
  for (i = n; i >= 0; i--) {
    if (i % 2 == 1) continue;
    if (s.substr(0, i / 2) == s.substr(i / 2, i / 2)) {
      ans = i / 2;
      break;
    }
  }
  cout << ans + (n - i);
  return 0;
}

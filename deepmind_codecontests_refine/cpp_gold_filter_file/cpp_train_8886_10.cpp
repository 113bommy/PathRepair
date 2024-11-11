#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) ans++;
  }
  cout << ans << endl;
  return 0;
}

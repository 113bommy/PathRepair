#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int u = 0;
    for (int j = 0; j <= s.size(); j++) {
      if (s[j] == '4' or s[j] == '7') u++;
    }
    if (u > k) ans++;
  }
  cout << n - ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.length() - 1;
  for (int i = 0; i <= n; i++) {
    if (s[i] != t[n - i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "yes";
  return 0;
}

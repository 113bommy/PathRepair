#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int d = 0;
  for (int i = 0; i < n; i++) {
    d += s[i] != t[i];
  }
  if (d % 2) {
    cout << "impossible";
    return 0;
  }
  int one = true;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i])
      cout << s[i];
    else {
      if (one)
        cout << s[i];
      else
        cout << t[i];
      one = !one;
    }
  }
  return 0;
}

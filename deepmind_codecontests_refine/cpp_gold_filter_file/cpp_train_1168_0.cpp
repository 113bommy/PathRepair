#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, int p, string s) {
  int i;
  for (i = s.size() - 2; i >= 0; i--) {
    if (s[i] == 'A') {
      if (p < a) break;
      p -= a;
    }
    if (s[i] == 'B') {
      if (p < b) break;
      p -= b;
    }
    while (i > 0 && s[i] == s[i - 1]) i--;
  }
  return i + 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, p;
    string s;
    cin >> a >> b >> p >> s;
    int res = solve(a, b, p, s);
    cout << res << endl;
  }
  return 0;
}

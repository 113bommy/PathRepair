#include <bits/stdc++.h>
using namespace std;
long long sr(string &s) {
  for (long long i = 0; i < s.size(); ++i)
    if (s[i] == '8') return i;
  return 0;
}
using namespace std;
int main() {
  long long n, m, t;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    if (n < 11)
      cout << "NO" << '\n';
    else {
      m = sr(s);
      if (m && (n - m >= 11))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}

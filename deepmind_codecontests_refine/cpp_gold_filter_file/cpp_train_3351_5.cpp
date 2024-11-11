#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    long long n = s.length();
    long long c = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        if (s[i] == t[j]) c++;
    }
    if (c == 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}

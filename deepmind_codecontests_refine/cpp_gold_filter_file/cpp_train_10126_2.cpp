#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    string s;
    long long n, i, j, l = 0, k;
    map<char, int> p;
    cin >> n;
    k = n;
    while (k--) {
      cin >> s;
      for (i = 0; i < s.size(); i++) {
        p[s[i] - 'a']++;
      }
    }
    for (i = 0; i < 26; i++) {
      if (p[i] % n != 0) {
        l = 1;
        break;
      }
    }
    if (l == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

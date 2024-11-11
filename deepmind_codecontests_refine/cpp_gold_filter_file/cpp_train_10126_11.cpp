#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[26] = {0};
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        a[s[j] - 'a']++;
      }
    }
    int f = 0;
    for (int i = 0; i < 26; i++)
      if (a[i] % n != 0) f = 1;
    if (f == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}

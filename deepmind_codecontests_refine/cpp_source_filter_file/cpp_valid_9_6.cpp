#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    for (int i = 0; i < n - 3; i++) {
      if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
        s[i] = '*';
      }
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '*') {
        c++;
      }
    }
    cout << (c) / 2 << "\n";
  }
}

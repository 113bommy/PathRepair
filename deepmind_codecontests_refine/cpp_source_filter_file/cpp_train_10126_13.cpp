#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    int cnt[30] = {0};
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int j = 0; j < s.length(); j++) {
        cnt[s[i] - 'a']++;
      }
    }
    bool ok = 1;
    for (int i = 0; i < 30; i++) {
      if (cnt[i] % n) ok = 0;
    }
    if (ok)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}

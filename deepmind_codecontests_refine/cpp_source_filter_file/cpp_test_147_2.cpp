#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'N') cnt++;
    }
    if (cnt == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}

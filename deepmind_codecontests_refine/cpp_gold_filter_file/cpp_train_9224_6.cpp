#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, i, j;
  cin >> t;
  string s[t];
  for (i = 0; i < t; i++) {
    int temp = 0;
    cin >> s[i];
    for (j = i - 1; j >= 0; j--) {
      if (s[i] == s[j]) {
        temp = 1;
        cout << "YES\n";
        break;
      }
    }
    if (temp != 1) {
      cout << "NO\n";
    }
  }
}

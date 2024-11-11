#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, c = 0;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 0) {
      for (int i = 1; i < s.length(); i += 2) {
        if (s[i] % 2 == 0) {
          cout << "2\n";
          c = 1;
          break;
        }
      }
      if (c == 1)
        continue;
      else {
        cout << "1\n";
        continue;
      }
    }
    if (n % 2 != 0) {
      for (int i = 0; i < s.length(); i += 2) {
        if (s[i] % 2 != 0) {
          cout << "1\n";
          c = 1;
          break;
        }
      }
      if (c == 1)
        continue;
      else {
        cout << "2\n";
        continue;
      }
    }
  }
  return 0;
}

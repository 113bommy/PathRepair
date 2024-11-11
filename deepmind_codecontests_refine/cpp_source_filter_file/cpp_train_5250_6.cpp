#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int mx = -1;
  for (int i = 'A'; i <= 'Z'; i++) {
    char now = char(i);
    int ghabl = -1;
    int ans = 1;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == now and ghabl == -1) ghabl = j;
      if (s[j] == now and ghabl != -1) {
        if ((j - ghabl) % 2 == 1) {
          ghabl = j;
          ans++;
          mx = max(mx, ans);
        }
      }
    }
  }
  cout << mx;
}

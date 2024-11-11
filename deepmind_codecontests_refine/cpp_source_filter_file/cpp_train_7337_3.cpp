#include <bits/stdc++.h>
using namespace std;
bool check[100];
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int ans = 0;
  for (int x = 0; x < s.size(); ++x) {
    if (!check[s[x] - 'a']) {
      ans++;
      check[s[x] - 'a'] = 1;
    }
  }
  cout << ((ans > n) ? "YES" : "NO") << endl;
  if (ans > n) {
    for (int x = 0; x < s.size(); ++x) {
      if (n) {
        if (check[s[x] - 'a']) {
          if (x) cout << endl;
          cout << s[x];
          check[s[x] - 'a'] = 0;
          n--;
        } else {
          cout << s[x];
        }
      } else
        cout << s[x];
    }
    cout << endl;
  }
}

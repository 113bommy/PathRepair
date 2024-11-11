#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> s;
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1] && s[i] != '?') {
      cout << "No\n";
      return 0;
    }
    cnt += (s[i] == '?');
  }
  cnt += (s[n - 1] == '?');
  if (cnt == 0) {
    cout << "No\n";
    return 0;
  }
  if (s[0] == '?' || s[n - 1] == '?') {
    cout << "Yes\n";
    return 0;
  }
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == '?') {
      if (s[i - 1] != '?' && s[i + 1] != '?') {
        if (s[i - 1] != s[i + 1]) {
          cout << "Yes\n";
          return 0;
        }
      } else {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}

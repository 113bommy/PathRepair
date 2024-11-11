#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int l = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] > 'Z') l++;
  }
  if (l >= s.length() / 2) {
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] <= 'Z') {
        cout << char(s[i] + 'a' - 'A');
      } else {
        cout << s[i];
      }
    }
    cout << endl;
  } else {
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] > 'Z') {
        cout << char(s[i] + 'A' - 'a');
      } else {
        cout << s[i];
      }
    }
    cout << endl;
  }
  return 0;
}

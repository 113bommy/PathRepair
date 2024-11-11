#include <bits/stdc++.h>
using namespace std;
int i;
bool fa(string s) {
  int j;
  for (j = 0; j < 26; j++) {
    if (count(s.begin(), s.end(), char('A' + j)) > 1) return false;
  }
  return true;
}
int q(string s) { return count(s.begin(), s.end(), '?'); }
vector<char> miss(string s) {
  vector<char> x;
  int j;
  for (j = 0; j < 26; j++) {
    if (count(s.begin(), s.end(), char('A' + j)) == 0) x.push_back('A' + j);
  }
  return x;
}
int main() {
  string s;
  cin >> s;
  bool succ = false;
  int n = s.size();
  for (int i = 0; i < n - 25; i++) {
    string a = s.substr(i, 26);
    if (fa(a)) {
      if (q(a) == 0) {
        int j = 0;
        for (int j = 0; j < i; j++) {
          if (s[j] == '?')
            cout << 'A';
          else
            cout << s[j];
        }
        cout << a;
        for (int j = i + 26; j < n; j++) {
          if (s[j] == '?')
            cout << 'A';
          else
            cout << s[j];
        }
        return 0;
      } else {
        vector<char> x = miss(a);
        int j;
        for (int j = 0; j < i; j++) {
          if (s[j] == '?')
            cout << 'A';
          else
            cout << s[j];
        }
        for (int j = 0; j < 26; j++) {
          if (a[j] == '?') {
            cout << x.back();
            x.pop_back();
          } else
            cout << a[j];
        }
        for (int j = i + 26; j < n; j++) {
          if (s[j] == '?')
            cout << 'A';
          else
            cout << s[j];
        }
        printf("\n");
      }
      succ = true;
      break;
    }
  }
  if (succ == false) {
    cout << -1 << "\n";
  }
  return 0;
}

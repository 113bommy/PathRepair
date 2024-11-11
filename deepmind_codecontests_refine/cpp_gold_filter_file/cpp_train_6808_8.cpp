#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  vector<char> a;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '.') {
      a.push_back('0');
    } else if (s[i] == '-' && s[i + 1] == '.') {
      a.push_back('1');
      i++;
    } else if (s[i] == '-' && s[i + 1] == '-') {
      a.push_back('2');
      i++;
    }
  }
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
  }
}

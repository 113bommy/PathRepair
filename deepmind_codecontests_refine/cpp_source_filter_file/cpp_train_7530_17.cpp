#include <bits/stdc++.h>
using namespace std;
int mx;
string s;
int main() {
  cin >> s;
  string d = "";
  for (int i = 25; i >= 0; --i) {
    char cur = i + 'a';
    int k = mx;
    for (int j = k + 1; j < s.size(); j++)
      if (s[j] == cur) {
        mx = j;
        d += s[j];
      }
  }
  cout << d;
  return 0;
}

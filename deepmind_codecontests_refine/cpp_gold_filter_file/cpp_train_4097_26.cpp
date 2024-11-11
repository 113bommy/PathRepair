#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<char> V;
  int index = -1;
  for (int i = 0; i < 26; ++i) {
    char c = 'z' - i;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == c) {
        if (j > index) {
          V.push_back(c);
          index = j;
        }
      }
    }
  }
  int i = V.size();
  for (int j = 0; j < i; ++j) cout << V[j];
  return 0;
}

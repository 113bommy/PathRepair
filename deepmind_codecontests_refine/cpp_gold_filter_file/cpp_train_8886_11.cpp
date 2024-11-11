#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, c;
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == s[i + 1] && i != s.size() - 1) {
      c += 1;
    }
  }
  cout << c;
  return 0;
}

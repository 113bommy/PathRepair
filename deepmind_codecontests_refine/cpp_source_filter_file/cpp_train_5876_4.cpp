#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[s1.length() - i - 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

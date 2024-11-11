#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k = 0;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      k++;
    }
  }
  if (2 * k < s.length()) {
    cout << 2 * k - 1;
  } else {
    cout << s.length();
  }
}

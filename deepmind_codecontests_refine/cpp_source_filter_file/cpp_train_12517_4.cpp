#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[102];
  cin >> s;
  for (int i = 0; i < 100; i++) {
    if (s[i] == 'H' || s[i] == '9' || s[i] == 'Q' || s[i] == 9) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
int main() {
  string str;
  cin >> str;
  int i;
  if (str.length() < 3) {
    cout << "NO\n";
    return 0;
  }
  for (i = 0; i < str.length() - 3; i++) {
    if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C') {
      cout << "YES\n";
      return 0;
    }
    if (str[i] == 'A' && str[i + 1] == 'C' && str[i + 2] == 'B') {
      cout << "YES\n";
      return 0;
    }
    if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'C') {
      cout << "YES\n";
      return 0;
    }
    if (str[i] == 'B' && str[i + 1] == 'C' && str[i + 2] == 'A') {
      cout << "YES\n";
      return 0;
    }
    if (str[i] == 'C' && str[i + 1] == 'B' && str[i + 2] == 'A') {
      cout << "YES\n";
      return 0;
    }
    if (str[i] == 'C' && str[i + 1] == 'A' && str[i + 2] == 'B') {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}

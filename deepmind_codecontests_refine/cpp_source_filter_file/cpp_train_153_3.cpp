#include <bits/stdc++.h>
using namespace std;
int main() {
  int users = 0;
  int output;
  string name;
  while (getline(cin, name)) {
    if (name[0] == '+') users++;
    if (name[0] == '-')
      users--;
    else {
      int n = name.length() - 1;
      for (int i = 0; i <= n; i++) {
        if (name[i] == ':') {
          output += users * (n - i);
          break;
        }
      }
    }
  }
  cout << output;
}

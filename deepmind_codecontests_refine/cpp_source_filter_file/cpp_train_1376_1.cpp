#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[30];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int j = 0; j < n; j++) {
    int l = s[j].length();
    if (s[j].at(l - 5) == 'm') {
      cout << "KOREAN" << endl;
    } else if (s[j].at(l - 2) == 'p') {
      cout << "FILIPINO" << endl;
    } else if (s[j].at(l - 1) == 'u') {
      cout << "JAPAN" << endl;
    }
  }
}

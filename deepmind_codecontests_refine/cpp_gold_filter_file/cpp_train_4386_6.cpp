#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cin.ignore(256, '\n');
  string s;
  cin >> s;
  int pos = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (s.at(i) > s.at(i + 1)) {
      pos = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != pos) {
      cout << s.at(i);
    }
  }
}

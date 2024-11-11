#include <bits/stdc++.h>
using namespace std;
int main() {
  string line;
  getline(cin, line);
  int a = 0;
  int i = 0;
  char c[4] = {'H', 'Q', '9', '+'};
  for (i; i < 4; i++) {
    if (line.find(c[i]) != string::npos) {
      a = 1;
    }
  }
  if (a > 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}

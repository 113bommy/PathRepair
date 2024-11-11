#include <bits/stdc++.h>
using namespace std;
bool isUnique(string s) {
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++)
      if (s[i] == s[j]) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  while (n < 9000) {
    n++;
    string x = to_string(n);
    if (isUnique(x)) {
      cout << x << endl;
      break;
    }
  }
}

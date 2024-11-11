#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c) {
  if (c != 'a' && c != 'o' && c != 'u' && c != 'e' && c != 'i') {
    return false;
  } else {
    return true;
  }
}
bool isConst(char c) {
  if (c != 'a' && c != 'o' && c != 'u' && c != 'e' && c != 'i') {
    return true;
  } else {
    return false;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a > c) {
      cout << c << "\n";
      continue;
    }
    if (c > b) {
      cout << c << "\n";
      continue;
    }
    if (c == 1) {
      cout << b + 1 << "\n";
    } else {
      cout << (c * (b / 2)) + c << "\n";
    }
  }
}

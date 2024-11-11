#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[1001];
  cin >> s;
  if (s[0] >= 65 && s[0] <= 90) {
    cout << (char)s[0] - 32;
    for (int i = 1; s[i] != '\0'; i++) {
      cout << s[i];
    }
  } else
    cout << s;
  return 0;
}

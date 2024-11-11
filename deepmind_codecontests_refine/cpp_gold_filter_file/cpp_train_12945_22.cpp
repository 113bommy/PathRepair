#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[11];
  cin >> s;
  int n = strlen(s);
  sort(s, s + n);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == s[n - 1]) cout << s[i];
  }
  return 0;
}

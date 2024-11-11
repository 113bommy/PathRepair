#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[11];
  cin >> s;
  char m = 'a';
  int i, n;
  for (i = 0; i < strlen(s); i++) {
    if (s[i] > m) {
      m = s[i];
    }
  }
  for (i = 0; i < strlen(s); i++) {
    if (s[i] == m) {
      n++;
    }
  }
  for (i = 0; i < n; i++) {
    cout << m;
  }
  cout << endl;
  return 0;
}

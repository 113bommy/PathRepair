#include <bits/stdc++.h>
using namespace std;
int main() {
  int flag = 0;
  char s[101], t[101];
  cin >> s >> t;
  if (strlen(s) == strlen(t) && strlen(s) <= 100) {
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] != t[strlen(t) - i - 1]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }
}

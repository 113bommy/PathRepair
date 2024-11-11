#include <bits/stdc++.h>
using namespace std;
char s[1050] = {0};
int main() {
  char sub[6] = "heidi";
  int i, length, j = 0;
  cin >> s;
  length = strlen(s);
  for (i = 0; i < length; i++) {
    if (s[i] == sub[j]) {
      j++;
    }
    if (j == 5) {
      break;
    }
  }
  if (j == 5) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}

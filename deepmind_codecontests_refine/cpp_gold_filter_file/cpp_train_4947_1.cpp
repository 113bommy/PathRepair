#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[2000000];
  char str2[2000000];
  scanf("%1999999s", str);
  scanf("%1999999s", str2);
  int p1 = 0, p2 = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == '0')
      p1++;
    else
      break;
  }
  for (int i = 0; i < strlen(str2); i++) {
    if (str2[i] == '0')
      p2++;
    else
      break;
  }
  if (strlen(str) - p1 > strlen(str2) - p2) {
    cout << ">";
  } else if (strlen(str) - p1 < strlen(str2) - p2) {
    cout << "<";
  } else {
    for (int i = p1; i < strlen(str); i++) {
      if (str[p1] > str2[p2]) {
        cout << ">";
        return 0;
      } else if (str[p1] < str2[p2]) {
        cout << "<";
        return 0;
      }
      p1++;
      p2++;
    }
    cout << "=";
  }
  return 0;
}

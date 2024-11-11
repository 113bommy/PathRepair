#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[101], str1[101], str2[101];
  int i, j, c = 0;
  cin >> str;
  cin >> str1;
  cin >> str2;
  int l, l1, l2;
  l = strlen(str);
  l1 = strlen(str1);
  l2 = strlen(str2);
  if (l2 == l + l1) {
    for (i = 0; i < l; i++) {
      for (j = 0; j < l2; j++) {
        if (str[i] == str2[j]) {
          c++;
          str2[j] == '0';
          break;
        }
      }
    }
    for (i = 0; i < l1; i++) {
      for (j = 0; j < l2; j++) {
        if (str1[i] == str2[j]) {
          c++;
          str2[j] == '0';
          break;
        }
      }
    }
    if (c == l2) {
      cout << "YES";
    } else
      cout << "NO";
  } else
    cout << "NO";
  return 0;
}

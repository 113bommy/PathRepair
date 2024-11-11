#include <bits/stdc++.h>
using namespace std;
int main() {
  char str1[100002], str2[100002];
  int len, i, flag = 0, count = 0;
  char result[100002];
  cin >> str1;
  cin >> str2;
  len = strlen(str1);
  for (int i = 0; i < len; i++) {
    if (str1[i] != str2[i]) count++;
  }
  if (count % 2 != 0)
    cout << "Impossible";
  else {
    for (i = 0; i < len; i++) {
      if (str1[i] != str2[i]) {
        if (flag == 0) {
          result[i] = str1[i];
          flag = 1;
        } else {
          result[i] = str2[i];
          flag = 0;
        }
      } else {
        result[i] = str1[i];
      }
    }
    result[i] = '\0';
    cout << result;
  }
  return 0;
}

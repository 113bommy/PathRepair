#include <bits/stdc++.h>
using namespace std;
int main() {
  char str1[100];
  int i, up = 0, low = 0;
  cin >> str1;
  for (i = 0; i < strlen(str1); i++) {
    if (str1[i] >= 65 && str1[i] <= 90) {
      up += 1;
    } else {
      low += 1;
    }
  }
  if (low >= up) {
    for (i = 0; i < strlen(str1); i++) {
      if (str1[i] >= 65 && str1[i] <= 90) {
        str1[i] = str1[i] + 32;
      }
    }
  } else {
    for (i = 0; i < strlen(str1); i++) {
      if (str1[i] >= 97 && str1[i] <= 122) {
        str1[i] = str1[i] - 32;
      }
    }
  }
  cout << str1;
  return 0;
}

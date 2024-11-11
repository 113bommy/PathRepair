#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[55];
  while (scanf("%s", &str) != EOF) {
    int len = strlen(str);
    bool flag = 0;
    int tag = 0;
    for (int i = 0; i < len - 1; i++) {
      if (str[i] != str[i + 1]) {
        tag = 1;
        break;
      }
    }
    if (len % 2) {
      int i = 0, j = len - 1;
      for (; i < len / 2, j >= len / 2 + 1; i++, j--) {
        if (str[i] != str[j]) {
          flag = 1;
          break;
        }
      }
    } else {
      int i = 0, j = len - 1;
      for (; i <= len / 2, j >= len / 2; i++, j--) {
        if (str[i] != str[j]) {
          flag = 1;
          break;
        }
      }
    }
    if (tag) {
      if (flag)
        cout << len << endl;
      else
        cout << len - 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}

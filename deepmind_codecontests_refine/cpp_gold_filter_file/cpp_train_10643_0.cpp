#include <bits/stdc++.h>
using namespace std;
int num(char ch) {
  int a[8] = {0};
  int i, n = ch;
  for (i = 0; i < 8; i++) {
    if (n & 1) a[i] = 1;
    n /= 2;
  }
  int ret = 0;
  for (i = 0; i < 8; i++) {
    ret = ret * 2 + a[i];
  }
  return 256 - ret;
}
int rev(char s) {
  int a[8] = {0};
  int i, n = s;
  for (i = 0; i < 8; i++) {
    if (n & 1) a[i] = 1;
    n /= 2;
  }
  int ret = 0;
  for (i = 0; i < 8; i++) {
    ret = ret * 2 + a[i];
  }
  return ret;
}
int main() {
  string str;
  while (getline(cin, str)) {
    int i;
    printf("%d\n", num(str[0]));
    for (i = 1; i < str.size(); i++) {
      int prvr = rev(str[i - 1]);
      int nowr = rev(str[i]);
      printf("%d\n", (256 - ((nowr - prvr + 256) % 256)) % 256);
    }
  }
  return 0;
}

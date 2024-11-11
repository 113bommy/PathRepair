#include <bits/stdc++.h>
int n, i;
char st[101];
bool pr() {
  bool ret;
  for (int j = 1; j < 27; ++j) {
    ret = true;
    for (int index = i + j; index < i + j * 5; index += j) {
      if (st[index] == '.' || index >= n) {
        ret = false;
        break;
      }
    }
    if (ret) {
      return true;
    }
  }
  return false;
}
int main() {
  bool tr = false;
  std::cin >> n;
  std::cin >> st;
  for (i = 0; i < n; ++i) {
    if (st[i] == '*') {
      tr = pr();
    }
    if (tr == true) {
      std::cout << "yes";
      break;
    }
  }
  if (i == n && tr == false) {
    std::cout << "no";
  }
}

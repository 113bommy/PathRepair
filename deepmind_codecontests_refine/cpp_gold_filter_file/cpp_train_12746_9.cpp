#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int flag;
  int i;
  int j;
  int flag1 = 0;
  char b[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
  for (i = 0; i < a.size(); i++) {
    flag = 0;
    for (j = 0; b[j] != '\0'; j++) {
      if (a.at(i) == b[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << "NO" << endl;
      flag1 = 1;
      break;
    }
  }
  if (!flag1) {
    flag = 0;
    for (i = 0, j = a.size() - 1; i < a.size() / 2; i++, j--) {
      if (a.at(i) != a.at(j)) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}

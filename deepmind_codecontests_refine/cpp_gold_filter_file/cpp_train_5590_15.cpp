#include <bits/stdc++.h>
using namespace std;
int main() {
  char* num = new char[1001];
  cin.getline(num, 1001);
  int len = strlen(num), ptPos = 0;
  for (int i = 0; i < len; ++i) {
    if (num[i] == '.') {
      ptPos = i;
      break;
    }
  }
  if (num[ptPos - 1] == '9') {
    cout << "GOTO Vasilisa." << endl;
    delete[] num;
    return 0;
  }
  if (num[ptPos + 1] >= '0' & num[ptPos + 1] <= '4') {
    char* dest = new char[ptPos];
    strncpy(dest, num, ptPos);
    dest[ptPos] = '\0';
    len = strlen(dest);
    cout << dest << endl;
    delete[] num, dest;
    return 0;
  } else {
    char c = (char)(((int)num[ptPos - 1]) + 1);
    char* dest = new char[ptPos];
    strncpy(dest, num, ptPos);
    dest[ptPos] = '\0';
    dest[ptPos - 1] = c;
    cout << dest << endl;
    delete[] num, dest;
    return 0;
  }
  return 0;
}

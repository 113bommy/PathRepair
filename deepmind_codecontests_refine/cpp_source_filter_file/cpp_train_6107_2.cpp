#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[100];
  int count0 = 0, count1 = 0, i = 0, flag = 0;
  cin >> str;
  while (str[i] != '\0') {
    if (str[i] == '0') {
      count0++;
      count1 = 0;
      if (count0 == 7) {
        cout << "YES";
        flag = 1;
        break;
      }
    } else {
      count1++;
      count0 = 0;
      if (count1 == 7) {
        cout << "YES";
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) cout << "NO";
}

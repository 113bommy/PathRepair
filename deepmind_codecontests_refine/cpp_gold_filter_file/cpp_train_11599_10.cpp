#include <bits/stdc++.h>
using namespace std;
int main() {
  int len;
  string str, n1, n2, n3;
  cin >> str;
  len = str.size();
  str += "11111";
  bool chk = true;
  for (int i = 0; i < len; i++) {
    n1 = str[i];
    n1 += str[i + 1];
    n1 += str[i + 2];
    n2 = str[i];
    n2 += str[i + 1];
    n3 = str[i];
    if ("144" == n1) {
      i = i + 2;
    } else if ("14" == n2) {
      i = i + 1;
    } else if ("1" == n3) {
      i = i;
    } else {
      chk = false;
      break;
    }
  }
  if (chk)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

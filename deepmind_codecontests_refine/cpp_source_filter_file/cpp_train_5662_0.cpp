#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  if (a.length() != b.length())
    cout << "NO" << endl;
  else {
    bool flag = 0;
    int i;
    for (i = 0; i < a.length(); i++)
      if (a[i] == '1') break;
    if (i == a.length()) {
      for (int j = 0; j < b.length(); j++)
        if (b[j] == '1') {
          flag = 1;
          break;
        }
    } else {
      int j;
      for (j = i; j < b.length(); j++) {
        if (b[j] == '1') break;
      }
      if (j == b.length()) flag = 1;
    }
    if (flag == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

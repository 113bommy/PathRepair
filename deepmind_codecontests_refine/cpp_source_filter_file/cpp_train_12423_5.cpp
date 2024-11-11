#include <bits/stdc++.h>
using namespace std;
string str, tmp, t = "0123456789";
int a[10];
int main() {
  int i, j;
  while (cin >> str >> tmp) {
    memset(a, 0, sizeof(a));
    int len = tmp.size();
    for (i = 0; i < len; i++) a[tmp[i] - '0']++;
    len = str.size();
    j = 9;
    for (i = 0; i < len && j > 0;)
      if (a[j] > 0) {
        if (str[i] < t[j])
          str[i] = t[i], a[j]--;
        else
          i++;
      } else {
        j--;
      }
    cout << str << endl;
  }
  return 0;
}

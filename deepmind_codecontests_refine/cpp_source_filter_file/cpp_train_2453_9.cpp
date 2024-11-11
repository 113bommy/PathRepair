#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
int main() {
  int n, i, j, k, l, i2, flag = -1;
  string str1, str2;
  m["monday"] = 1;
  m["tuesday"] = 2;
  m["wednesday"] = 3;
  m["thurday"] = 4;
  m["friday"] = 5;
  m["saturday"] = 6;
  m["sunday"] = 7;
  cin >> str1 >> str2;
  int a[2];
  a[0] = m[str1];
  a[1] = m[str2];
  int dif = 0;
  if (a[1] < a[0])
    dif = 7 - a[0] + a[1];
  else
    dif = a[1] - a[0];
  if (dif == 0 || dif == 3 || dif == 2) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}

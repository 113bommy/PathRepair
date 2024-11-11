#include <bits/stdc++.h>
using namespace std;
int main() {
  char str1[106], str2[106];
  int l1, res;
  cin >> str1 >> str2;
  l1 = strlen(str2);
  reverse(str2, str2 + l1);
  res = strcmp(str1, str2);
  if (res == 0)
    cout << "YES";
  else
    cout << "NO";
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100000];
  gets(a);
  int len = strlen(a);
  string s;
  for (int i = 0; i < len; i++) {
    if (a[i] != ' ') s += a[i];
  }
  int si = s.size();
  if (s[si - 2] == 'a' || s[si - 2] == 'e' || s[si - 2] == 'i' ||
      s[si - 2] == 'o' || s[si - 2] == 'u' || s[si - 2] == 'y')
    cout << "YES";
  else
    cout << "NO";
}

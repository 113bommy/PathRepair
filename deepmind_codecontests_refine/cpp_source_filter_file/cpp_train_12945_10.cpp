#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[15];
  scanf("%s", &s);
  int len = strlen(s);
  sort(s, s + len);
  int i = len - 1;
  cout << s[i];
  while (i-- >= 0 && s[i] == s[len - 1]) cout << s[len - 1];
  cout << endl;
}

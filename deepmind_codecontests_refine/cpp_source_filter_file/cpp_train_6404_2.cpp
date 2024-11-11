#include <bits/stdc++.h>
using namespace std;
int main() {
  char s1[100];
  char s2[100];
  gets(s1);
  gets(s2);
  int l, m;
  l = strlen(s1);
  for (m = 0; m < l; m++) {
    if (s1[m] == s2[m]) {
      cout << 0;
    } else {
      cout << 1;
    }
  }
  cout << endl;
  return 0;
}

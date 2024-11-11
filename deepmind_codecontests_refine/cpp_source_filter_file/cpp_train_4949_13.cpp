#include <bits/stdc++.h>
using namespace std;
int main() {
  char s1[101], s2[101];
  cin >> s1 >> s2;
  int l1 = strlen(s1), l2 = strlen(s2);
  int p = 1;
  if (l1 == l2) {
    for (int i = 0; i < l1; i++) {
      if (s1[i] != s2[i]) {
        p = 0;
        break;
      }
    }
    if (p)
      cout << s1 << endl;
    else
      cout << "1\n";
  } else
    cout << "1" << endl;
  return 0;
}

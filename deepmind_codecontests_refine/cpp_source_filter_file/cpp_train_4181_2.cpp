#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  while (cin >> n) {
    while (n--) {
      char s[1000];
      cin >> s;
      int len = strlen(s), a[30];
      memset(a, 0., sizeof(a));
      for (int i = 0; i < len; i++) {
        a[s[i] - 'a']++;
      }
      int flag = 0, f = 0;
      for (int i = 0; i < 26; i++) {
        if (flag && a[i - 1] == 0 && a[i] == 1) f = 1;
        if (a[i] == 1) flag = 1;
        if (a[i] == 2) f = 1;
      }
      if (f) {
        cout << "No" << endl;
      } else
        cout << "Yes" << endl;
    }
  }
  return 0;
}

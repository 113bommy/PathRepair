#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int N = 1005;
using namespace std;
char s[N];
int a[5][5];
int main() {
  cin >> s;
  memset(a, 0, sizeof(a));
  int len = strlen(s);
  int k = 1;
  for (int i = 0; i < len; i++) {
    if (s[i] == '0') {
      while (a[k][1]) k++;
      cout << k << " 1" << endl;
      a[k][1] = 1;
      if (k == 4) {
        for (int j = 1; j <= 4; j++) {
          a[j][1] = 0;
        }
      }
      k = 1;
    }
    if (s[i] == '1') {
      while (a[k][3]) k += 2;
      cout << k << " 3" << endl;
      a[k][3] = 1;
      if (k == 3) {
        for (int j = 1; j <= 4; j++) {
          a[j][3] = 0;
        }
      }
      k = 1;
    }
  }
  return 0;
}

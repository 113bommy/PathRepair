#include <bits/stdc++.h>
using namespace std;
int main() {
  char s1[1005], s2[1005];
  int c1 = 0, c2 = 0;
  gets(s1);
  gets(s2);
  for (int i = 0; s1[i]; i++) {
    if (s1[i] == '1') {
      c1++;
    }
  }
  for (int i = 0; i < s2[i]; i++) {
    if (s2[i] == '1') {
      c2++;
    }
  }
  if (c1 % 2 == 0 && c1 >= c2) {
    cout << "YES" << endl;
    return 0;
  }
  if (c1 % 2 == 0 && c1 < c2) {
    cout << "NO" << endl;
    return 0;
  }
  if (c1 % 2 == 1) c1++;
  if (c1 >= c2) {
    cout << "YES" << endl;
    return 0;
  }
  if (c1 < c2) {
    cout << "NO" << endl;
  }
  return 0;
}

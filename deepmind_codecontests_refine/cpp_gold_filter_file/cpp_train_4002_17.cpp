#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[110];
  cin >> a;
  int i, l, flag = 0, Flag = 0, F1 = 0;
  l = strlen(a);
  if (l < 5) {
    cout << "Too weak";
    return 0;
  }
  for (i = 0; i < l; i++) {
    if (a[i] > 64 && a[i] < 91) Flag = 1;
    if (a[i] > 96 && a[i] < 123) flag = 1;
    if (a[i] > 47 && a[i] < 58) F1 = 1;
  }
  if (flag == 1 && Flag == 1 && F1 == 1)
    cout << "Correct";
  else
    cout << "Too weak";
  return 0;
}

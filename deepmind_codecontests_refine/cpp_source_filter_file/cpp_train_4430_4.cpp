#include <bits/stdc++.h>
using namespace std;
int a[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
char s[10];
int main() {
  int num = 0;
  for (int i = 0; i <= 14; i++) {
    if (num >= 2) break;
    cout << a[i] << endl;
    cin >> s;
    if (s[0] == 'y') {
      num++;
      if (i <= 2) {
        cout << a[i] * a[i] << endl;
        cin >> s;
        if (s[0] == 'y') num++;
      }
    }
  }
  if (num <= 1)
    cout << "prime" << endl;
  else
    cout << "composite" << endl;
  cout << flush;
  return 0;
}

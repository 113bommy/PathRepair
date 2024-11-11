#include <bits/stdc++.h>
using namespace std;
char bear[] = {'b', 'e', 'a', 'r'};
int main() {
  string s;
  int i, j, k, ult, cant;
  cin >> s;
  i = j = cant = 0;
  ult = -1;
  for (k = 0; k < s.length(); k++) {
    if (s[k] == bear[j]) {
      j++;
    } else {
      j = 0;
      if (s[k] == bear[j]) {
        j++;
      }
    }
    if (j == 4) {
      if (k == 3) {
        if (k == s.length() - 1) {
          cant = 1;
        } else {
          cant = s.length() - k;
        }
      } else {
        if (k == s.length() - 1) {
          cant += (1 + ((k - 3) - (ult + 1)));
        } else {
          cant += (1 + (s.length() - (k + 1)) + ((k - 3) - (ult + 1)) +
                   ((s.length() - (k + 1)) * ((k - 3) - (ult + 1))));
        }
      }
      ult = k - 3;
      j = 0;
    }
  }
  cout << cant << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char input[111];
  cin.getline(input, 111);
  if (strlen(input) == 2)
    n = 10;
  else
    n = input[0] - '0';
  for (int j = 1; j <= n; j++) {
    cin.getline(input, 111);
    bool f = false, r = false;
    if (strlen(input) <= 5) {
      if (strcmp(input, "miao.") == 0)
        r = true;
      else if (strcmp(input, "lala.") == 0)
        f = true;
    } else {
      char tmp[6];
      for (int i = 0; i < 5; i++) {
        tmp[i] = input[i];
      }
      tmp[5] = '\0';
      if (strcmp(tmp, "miao.") == 0) {
        r = true;
      }
      int k = strlen(input) - 1;
      for (int i = 0; i < 5; i++) {
        tmp[4 - i] = input[k - i];
      }
      tmp[5] = '\0';
      if (strcmp(tmp, "lala.") == 0) {
        f = true;
      }
    }
    if (f && !r)
      cout << "Freda's" << endl;
    else if (r && !f)
      cout << "Rainbow's" << endl;
    else
      cout << "OMG>.< I don't know!" << endl;
  }
}

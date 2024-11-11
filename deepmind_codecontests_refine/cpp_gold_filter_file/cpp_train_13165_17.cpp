#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch[3];
  int get[2], res = 1, j, i;
  gets(ch);
  for (i = 0; ch[i] != '\0'; i++) {
    if (ch[i] == '0')
      get[i] = 2;
    else if (ch[i] == '1')
      get[i] = 7;
    else if (ch[i] == '2')
      get[i] = 2;
    else if (ch[i] == '3')
      get[i] = 3;
    else if (ch[i] == '4')
      get[i] = 3;
    else if (ch[i] == '5')
      get[i] = 4;
    else if (ch[i] == '6')
      get[i] = 2;
    else if (ch[i] == '7')
      get[i] = 5;
    else if (ch[i] == '8')
      get[i] = 1;
    else if (ch[i] == '9')
      get[i] = 2;
  }
  for (j = 0; j < i; j++) {
    res *= get[j];
  }
  cout << res << endl;
  return 0;
}

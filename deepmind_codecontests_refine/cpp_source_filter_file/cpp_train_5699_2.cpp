#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[7] = {"000000"};
  char b[7];
  scanf("%s", b);
  for (int i = 0; i < 6; i++) {
    if (b[i] == 'R')
      a[0]++;
    else if (b[i] == 'O')
      a[1]++;
    else if (b[i] == 'Y')
      a[2]++;
    else if (b[i] == 'G')
      a[3]++;
    else if (b[i] == 'B')
      a[4]++;
    else if (b[i] == 'V')
      a[5]++;
  }
  sort(a, a + 6);
  if (strcmp(a, "000006") == 0)
    cout << 1 << endl;
  else if (strcmp(a, "000015") == 0)
    cout << 1 << endl;
  else if (strcmp(a, "000024") == 0)
    cout << 2 << endl;
  else if (strcmp(a, "000114") == 0)
    cout << 2 << endl;
  else if (strcmp(a, "000033") == 0)
    cout << 2 << endl;
  else if (strcmp(a, "000123") == 0)
    cout << 3 << endl;
  else if (strcmp(a, "001113") == 0)
    cout << 5 << endl;
  else if (strcmp(a, "000222") == 0)
    cout << 6 << endl;
  else if (strcmp(a, "001122") == 0)
    cout << 8 << endl;
  else if (strcmp(a, "011112") == 0)
    cout << 18 << endl;
  else if (strcmp(a, "111111") == 0)
    cout << 30 << endl;
  return 0;
}

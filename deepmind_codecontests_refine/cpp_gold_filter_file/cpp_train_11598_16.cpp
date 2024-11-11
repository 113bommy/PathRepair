#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  char c, a[15], n = 0;
  do {
    c = getchar();
    if (c != '\n') {
      n++;
      a[n] = c;
    }
  } while (c != '\n');
  int i = n, flag = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] != '1' && a[i] != '4') flag++;
  while (i > 0) {
    if (a[i] == '1')
      i--;
    else {
      if (i >= 2) {
        if (a[i - 1] == '1')
          i = i - 2;
        else {
          if (i >= 3) {
            if (a[i - 2] == '1')
              i = i - 3;
            else {
              flag++;
              break;
            }
          } else {
            flag++;
            break;
          }
        }
      } else {
        flag++;
        break;
      }
    }
  }
  if (flag == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return EXIT_SUCCESS;
}

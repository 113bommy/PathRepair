#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(0));
  int n, i, j;
  char **a, q;
  cin >> n;
  scanf("%c", &q);
  a = new char *[n];
  for (i = 0; i < n; i++) a[i] = new char[20];
  for (i = 0; i < n; i++) fgets(a[i], 20, stdin);
  for (i = 0; i < n; i++) {
    j = 0;
    if (strstr(a[i], " rat") != NULL) {
      while (a[i][j] != ' ') {
        cout << a[i][j];
        j++;
      }
      cout << endl;
    }
  }
  for (i = 0; i < n; i++) {
    j = 0;
    if ((strstr(a[i], " woman") != NULL) || (strstr(a[i], " child") != NULL)) {
      while (a[i][j] != ' ') {
        cout << a[i][j];
        j++;
      }
      cout << endl;
    }
  }
  for (i = 0; i < n; i++) {
    j = 0;
    if (strstr(a[i], " man") != NULL) {
      while (a[i][j] != ' ') {
        cout << a[i][j];
        j++;
      }
      cout << endl;
    }
  }
  for (i = 0; i < n; i++) {
    j = 0;
    if (strstr(a[i], " captain") != NULL) {
      while (a[i][j] != ' ') {
        cout << a[i][j];
        j++;
      }
      cout << endl;
    }
  }
  for (i = 0; i < n; i++) delete[] a[i];
  delete[] a;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  char m[][15] = {"",        "January",  "February", "March",  "April",
                  "May",     "June",     "July",     "August", "September",
                  "October", "November", "December"};
  char c[15];
  int i, x, n, t = 0;
  scanf("%s %d", &c, &x);
  if (strcmp(c, "January") == 0) {
    t = 1;
  } else if (c[0] == 'F') {
    t = 2;
  } else if (strcmp(c, "March") == 0) {
    t = 3;
  } else if (strcmp(c, "April") == 0) {
    t = 4;
  } else if (c[0] == 'M') {
    t = 5;
  } else if (strcmp(c, "June") == 0) {
    t = 6;
  } else if (strcmp(c, "July") == 0) {
    t = 7;
  } else if (strcmp(c, "August") == 0) {
    t = 8;
  } else if (c[0] == 'S') {
    t = 9;
  } else if (c[0] == 'O') {
    t = 10;
  } else if (c[0] == 'N') {
    t = 11;
  } else if (c[0] == 'D') {
    t = 12;
  }
  if (x == 0) {
    cout << c << endl;
    return 0;
  }
  for (i = 0; i < x; i++) {
    t++;
    if (t > 12) {
      t = 1;
    }
  }
  cout << m[t] << "\n";
  return 0;
}

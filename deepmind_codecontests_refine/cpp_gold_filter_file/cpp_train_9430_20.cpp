#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[500];
  char b[500];
  char c[500];
  long long int count = 0, i, k, l, j, zount = 0, xount = 0, n = 3;
  gets(a);
  gets(b);
  gets(c);
  for (j = 0; j < strlen(a); j++) {
    if (a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' ||
        a[j] == 'u') {
      count++;
    }
  }
  for (j = 0; j < strlen(b); j++) {
    if (b[j] == 'a' || b[j] == 'e' || b[j] == 'i' || b[j] == 'o' ||
        b[j] == 'u') {
      zount++;
    }
  }
  for (j = 0; j < strlen(c); j++) {
    if (c[j] == 'a' || c[j] == 'e' || c[j] == 'i' || c[j] == 'o' ||
        c[j] == 'u') {
      xount++;
    }
  }
  if (count == 5 && zount == 7 && xount == 5) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}

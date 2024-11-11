#include <bits/stdc++.h>
using namespace std;
char a[1000001];
int main() {
  int sum = 0, aux = 0, i;
  cin >> a;
  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] == 'h' && a[i + 1] == 'e' && a[i + 2] == 'a' && a[i + 3] == 'v' &&
        a[i + 4] == 'y') {
      aux++;
    }
    if (a[i] == 'm' && a[i + 1] == 'e' && a[i + 2] == 't' & a[i + 3] == 'a' &&
        a[i + 4] == 'l') {
      sum += aux;
    }
  }
  cout << sum;
  return 0;
}

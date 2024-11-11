#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, i;
  char a[3];
  cin >> n;
  while (n--) {
    for (i = 0; i < 3; i++) {
      cin >> a[i];
    }
    if (a[1] == '+') x++;
    if (a[1] == '-') x--;
  }
  cout << x;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j = 0, k = 0, n;
  char a[101];
  cin >> a;
  n = strlen(a);
  for (i = 1; i <= n; i++) {
    if (a[i] == '0') {
      j = 0;
      k++;
    } else if (a[i] == '1') {
      k = 0;
      j++;
    }
    if (k == 7 || j == 7) break;
  }
  if (k == 7)
    cout << "Yes";
  else if (j == 7)
    cout << "Yes";
  else {
    cout << "No";
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r, i, j, k, b = 0, c = 0, d = 0, e = 0;
  char a[103];
  cin >> a;
  n = strlen(a);
  for (i = 0; i < n; i++) {
    if (a[i] >= 'a' && a[i] <= 'z') b = 1;
    if (a[i] >= 'A' && a[i] <= 'Z') c = 1;
    if (a[i] >= 0 && a[i] <= 9) d = 1;
  }
  if (n >= 5 && b == 1 && c == 1 && d == 1)
    cout << "Correct";
  else
    cout << "Too weak";
  return 0;
}

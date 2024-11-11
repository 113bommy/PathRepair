#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char a[200];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int jj, j;
  for (int k = 1; k < n; k++)
    for (int i = 0; i < n; i++) {
      jj = 0;
      j = i;
      while (j < n && a[j] == '*') {
        jj++;
        j += k;
      }
      if (jj > 4) {
        cout << "yes";
        return 0;
      }
    }
  cout << "no";
  return 0;
}

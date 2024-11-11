#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[50][20], b[20];
  cin >> b;
  for (int c = 0; c < 5; c++) {
    cin >> a[c];
  }
  int i, J, r = 0;
  for (i = 0; i < 5; i++) {
    if (a[i][0] == b[0] || a[i][1] == b[1]) r++;
  }
  if (r == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}

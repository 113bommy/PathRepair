#include <bits/stdc++.h>
using namespace std;
char a[9];
int main() {
  for (int i = 0; i < 9; i++) {
    cin >> a[i];
  }
  if (a[0] == a[8] && a[1] == a[7] && a[2] == a[6] && a[3] == a[5])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

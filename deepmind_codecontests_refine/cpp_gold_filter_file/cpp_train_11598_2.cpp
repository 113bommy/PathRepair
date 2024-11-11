#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int n = a.size(), i, s = 0;
  for (i = 0; i <= n - 1; i++) {
    if ((a[i] == '1') && (a[i + 1] == '4') && (a[i + 2] == '4'))
      i = i + 2;
    else if ((a[i] == '1') && (a[i + 1] == '4'))
      i = i + 1;
    else if (a[i] == '1' && i == 0)
      i = i;
    else if (a[i] == '1' && i > 0)
      i = i;
    else
      s++;
  }
  if (s == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

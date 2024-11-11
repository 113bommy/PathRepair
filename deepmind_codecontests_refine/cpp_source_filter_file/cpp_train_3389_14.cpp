#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n, m;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string a;
      cin >> a;
      if (a[0] == 'C' || a[0] == 'M' || a[0] == 'Y') flag = false;
    }
  }
  if (flag == true)
    cout << "#Black&White";
  else
    cout << "#Color";
}

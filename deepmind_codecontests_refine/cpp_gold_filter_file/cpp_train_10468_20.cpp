#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  if ((a[0] == 'a' && a[1] == '1') || (a[0] == 'a' && a[1] == '8') ||
      (a[0] == 'h' && a[1] == '1') || (a[0] == 'h' && a[1] == '8'))
    cout << "3";
  else if ((a[0] == 'h') || (a[0] == 'a') || (a[1] == '1') || (a[1] == '8'))
    cout << "5";
  else
    cout << "8";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  if ((a[6] - '0') % 2 == 0) {
    cout << "0";
  } else {
    cout << "1";
  }
  return 0;
}

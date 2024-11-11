#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  if ((a[6] - '0') % 2 == 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}

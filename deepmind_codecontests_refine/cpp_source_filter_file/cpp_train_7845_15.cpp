#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    if (360 % (180 - a) == 0) {
      cout << "YES";
    } else
      cout << "NO";
  }
  return 0;
}

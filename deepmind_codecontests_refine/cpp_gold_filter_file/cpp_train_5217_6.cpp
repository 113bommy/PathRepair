#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 10) {
    cout << "0\n";
    return 0;
  } else if ((n == 12) || (n == 13) || (n == 14) || (n == 15) || (n == 16) ||
             (n == 17) || (n == 18) || (n == 19)) {
    cout << "4\n";
    return 0;
  } else if (n == 20) {
    cout << "15\n";
    return 0;
  } else if (n == 21) {
    cout << "4\n";
    return 0;
  } else if (n == 11) {
    cout << "4\n";
    return 0;
  } else {
    cout << "0\n";
    return 0;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int a, b, ans = 0;
    cin >> a >> b;
    if (a > b) {
      if (a % b == 0)
        cout << "0" << endl;
      else
        cout << b - (a % b) << endl;
    } else if (a == b) {
      cout << "0" << endl;
    } else {
      cout << b - a << endl;
    }
  }
  return 0;
}

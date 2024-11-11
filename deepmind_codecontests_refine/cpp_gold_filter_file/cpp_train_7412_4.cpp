#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long a, b;
    cin >> a >> b;
    if (a * 2 < b || 2 * b < a)
      cout << "no" << endl;
    else if (a % 3 == 0 && b % 3 == 0)
      cout << "yes" << endl;
    else if (a % 3 == 2 && b % 3 == 1)
      cout << "yes" << endl;
    else if (a % 3 == 1 && b % 3 == 2)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}

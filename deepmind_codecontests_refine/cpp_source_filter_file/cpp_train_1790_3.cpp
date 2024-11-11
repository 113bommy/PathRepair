#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long int nn;
    cin >> nn;
    if (nn == 1) {
      cout << "3" << endl;
    } else if (nn == 4)
      cout << "2" << endl;
    else if (nn % 2 == 0)
      cout << "0" << endl;
    else
      cout << "1" << endl;
  }
  return 0;
}

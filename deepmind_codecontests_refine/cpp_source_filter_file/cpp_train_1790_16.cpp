#include <bits/stdc++.h>
using namespace std;
long long a, i, k;
int main() {
  cin >> a;
  for (i = 0; i <= a; i++) {
    cin >> k;
    if (k == 2) cout << "2" << endl;
    if (k % 2 == 0 && k != 2)
      cout << "0" << endl;
    else if (k % 2 == 1)
      cout << "1" << endl;
  }
}

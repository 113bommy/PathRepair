#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    long long int a, b;
    cin >> a >> b;
    long long int c = (a < b ? a : b);
    long long int hcf = 1;
    for (long long int i = 2; i <= c; i++) {
      if (a % i == 0 && b % i == 0) {
        hcf = i;
        break;
      }
    }
    if (hcf == 1)
      cout << "Infinite";
    else
      cout << "Finite";
    cout << endl;
  }
}

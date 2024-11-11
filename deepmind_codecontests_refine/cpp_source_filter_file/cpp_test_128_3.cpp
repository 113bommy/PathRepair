#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 10)
      cout << "2 7 1" << endl;
    else if (n & 1) {
      if (((n - 1) / 2) & 1)
        cout << (n / 2) - 2 << " " << (n / 2) + 2 << " 1" << endl;
      else
        cout << (n / 2) - 1 << " " << (n / 2) + 1 << " 1" << endl;
    } else {
      if ((n / 2) & 1)
        cout << (n / 2) - 3 << " " << (n / 2) + 1 << " 2" << endl;
      else
        cout << (n / 2) - 2 << " " << (n / 2) << " 2" << endl;
    }
  }
}

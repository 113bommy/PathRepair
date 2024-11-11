#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c;
  cin >> n;
  if (n == 3) {
    cout << "1"
         << " "
         << "1"
         << " "
         << "1" << endl;
  } else if ((n - 2) % 3 == 0) {
    cout << "1"
         << " "
         << "2"
         << " " << n - 3 << endl;
  } else {
    cout << "1"
         << " "
         << "1"
         << " " << n - 2 << endl;
  }
}

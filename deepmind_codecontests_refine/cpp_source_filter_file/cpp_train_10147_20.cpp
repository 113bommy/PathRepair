#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "white" << endl;
    cout << n - 1 << " " << n << endl;
    return 0;
  }
  cout << "black" << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << (2 * (pow(2, n / 2) - 1)) << endl;
  }
}

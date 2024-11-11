#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << abs(2 * (pow(-4, n / 2) - 1) / 5) << endl;
  }
}

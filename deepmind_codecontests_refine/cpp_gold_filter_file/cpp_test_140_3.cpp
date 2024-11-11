#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int x;
    cin >> x;
    long long int a = pow(x, 0.1666666666667);
    long long int b = pow(x, 0.3333333333334);
    long long int c = pow(x, 0.5);
    cout << b + c - a << endl;
  }
  return 0;
}

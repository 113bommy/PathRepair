#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int y = a / b;
    cout << (a ^ y) + (b ^ y) << endl;
  }
}

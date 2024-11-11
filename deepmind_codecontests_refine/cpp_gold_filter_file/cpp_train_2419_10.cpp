#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int z = ceil((double)a / b);
    long long int x = b * z - a;
    cout << x << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (2 * a != b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

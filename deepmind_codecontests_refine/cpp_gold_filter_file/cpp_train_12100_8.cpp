#include <bits/stdc++.h>
using namespace std;
long long int arr[300000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b) || (a + b) > (y - x))
      cout << "-1\n";
    else
      cout << (y - x) / (a + b) << "\n";
  }
}

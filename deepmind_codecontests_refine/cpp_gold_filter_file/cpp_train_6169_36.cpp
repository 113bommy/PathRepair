#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 4)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}

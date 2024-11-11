#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n;
    n = n < 2 ? 0 : n - 2;
    cout << n << endl;
  }
  return 0;
}

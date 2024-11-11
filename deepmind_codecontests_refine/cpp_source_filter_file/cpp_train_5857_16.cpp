#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, r;
    cin >> n >> r;
    if (n >= r)
      cout << r * (r + 1) / 2;
    else
      cout << (n * (n + 1) / 2) - (n - 1) << endl;
  }
  return 0;
}

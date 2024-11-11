#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, r;
    cin >> n >> r;
    unsigned long long int sum = 0;
    if (n >= r) {
      sum = (r * (r + 1)) / 2;
    } else
      sum = ((n * (n - 1)) / 2) + 1;
    cout << sum << endl;
  }
}

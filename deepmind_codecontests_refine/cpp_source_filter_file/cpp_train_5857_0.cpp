#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, r;
    cin >> n >> r;
    if (n < r) {
      n--;
      cout << n * (n + 1) / 2 + 1 << "\n";
    } else
      cout << r * (r + 1) / 2 << "\n";
  }
  return 0;
}

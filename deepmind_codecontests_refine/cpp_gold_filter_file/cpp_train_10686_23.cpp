#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, q, x;
  cin >> n >> q;
  for (; q; q--) {
    cin >> x;
    while (x % 2 == 0) x = n + x / 2;
    cout << (x + 1) / 2 << "\n";
  }
  return 0;
}

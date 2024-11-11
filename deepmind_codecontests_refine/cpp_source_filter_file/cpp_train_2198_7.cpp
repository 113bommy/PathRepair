#include <bits/stdc++.h>
using namespace std;
size_t popcount(size_t n) {
  bitset<sizeof(size_t) * CHAR_BIT> b(n);
  return b.count();
}
int main() {
  int t, a;
  cin >> t;
  while (t--) {
    cin >> a;
    cout << pow(2, popcount(a)) << '\n';
  }
}

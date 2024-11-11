#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, q, s;
  cin >> t >> q >> s;
  int total = t;
  int count = 0;
  while (t > q) {
    q = q * s;
    count++;
  }
  cout << count;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, q, s;
  cin >> t >> s >> q;
  int total = t;
  int count = 0;
  while (total > q) {
    q = q * s;
    count++;
  }
  cout << count;
  return 0;
}

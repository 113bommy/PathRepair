#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long p, v, l, r;
    cin >> p >> v >> l >> r;
    cout << p / v - r / v + (l - 1) / v << endl;
  }
  return 0;
}

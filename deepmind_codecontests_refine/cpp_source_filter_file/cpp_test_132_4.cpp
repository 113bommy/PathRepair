#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    vector<long long> v(7);
    for (auto &i : v) cin >> i;
    long long a = v[0];
    long long b = v[1];
    long long c = v[5] - v[2];
    cout << a << ' ' << b << ' ' << c << '\n';
  }
  return 0;
}
